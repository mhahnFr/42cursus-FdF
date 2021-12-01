#include <stdlib.h>

#include "model.h"
#include "utils/math/vector.h"
#include "utils/math/matrix.h"

t_model3D	*model3D_new(
				size_t *vertices_count_ar,
				size_t vertices_count_length,
				t_vertex3D ***vertices)
{
	t_model3D	*ret;

	if (vertices == NULL || vertices_count_ar == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_model3D));
	if (ret != NULL)
		model3D_create(
			ret,
			vertices_count_ar,
			vertices_count_length,
			vertices);
	return (ret);
}

void	model3D_create(
		t_model3D *this,
		size_t *vertices_count_ar,
		size_t vertices_count_length,
		t_vertex3D ***vertices)
{
	if (this == NULL || vertices == NULL || vertices_count_ar == NULL)
		return ;
	this->vertices = vertices;
	this->vertex_count = vertices_count_ar;
	this->vertex_count_length = vertices_count_length;
	this->x_angle = 0;
	this->y_angle = 0;
	this->z_angle = 0;
	this->mover = vector_new(0, 0, 0);
	this->movements = matrix_new(NULL, 4, 4);
	matrix_fill_neutral(this->movements);
	this->rotation_x = matrix_new(NULL, 4, 4);
	matrix_fill_neutral(this->rotation_x);
	this->rotation_y = matrix_new(NULL, 4, 4);
	matrix_fill_neutral(this->rotation_y);
	this->rotation_z = matrix_new(NULL, 4, 4);
	matrix_fill_neutral(this->rotation_z);
	this->scale = matrix_new(NULL, 4, 4);
	matrix_fill_neutral(this->scale);
	this->scaler = vector_new(1, 1, 1);
}

void	model3D_destroy(t_model3D *this)
{
	size_t	i;
	size_t	j;

	if (this == NULL)
		return ;
	i = 0;
	while (i < this->vertex_count_length)
	{
		j = 0;
		while (j < this->vertex_count[i])
		{
			vertex3D_destroy(this->vertices[i][j]);
			j++;
		}
		i++;
	}
	vector_destroy(this->mover);
	matrix_destroy(this->movements);
	matrix_destroy(this->rotation_x);
	matrix_destroy(this->rotation_y);
	matrix_destroy(this->rotation_z);
	matrix_destroy(this->scale);
	vector_destroy(this->scaler);
}

void	model3D_delete(t_model3D *this)
{
	size_t	i;
	size_t	j;

	if (this == NULL)
		return ;
	model3D_destroy(this);
	i = 0;
	while (i < this->vertex_count_length)
	{
		j = 0;
		while (j < this->vertex_count[i])
			vertex3D_delete(this->vertices[i][j++]);
		free(this->vertices[i++]);
	}
	free(this->vertices);
	free(this->vertex_count);
	matrix_delete(this->movements);
	matrix_delete(this->rotation_x);
	matrix_delete(this->rotation_y);
	matrix_delete(this->rotation_z);
	matrix_delete(this->scale);
	vector_delete(this->mover);
	vector_delete(this->scaler);
	free(this);
}
