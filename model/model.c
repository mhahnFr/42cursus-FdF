#include <stdlib.h>

#include "model.h"

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
		{
			vertex3D_delete(this->vertices[i][j]);
			j++;
		}
		free(this->vertices[i]);
		i++;
	}
	free(this->vertices);
	free(this->vertex_count);
	free(this);
}
