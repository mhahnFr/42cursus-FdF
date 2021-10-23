#include <stdlib.h>

#include "model.h"

t_model3D	*model3D_new(t_vertex3D **vertices, size_t vertex_count)
{
	t_model3D	*ret;

	if (vertices == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_model3D));
	if (ret != NULL)
		model3D_create(ret, vertices, vertex_count);
	return (ret);
}

void	model3D_create(
		t_model3D *this,
		t_vertex3D **vertices,
		size_t vertex_count)
{
	if (this == NULL || vertices == NULL)
		return ;
	this->vertices = vertices;
	this->vertex_count = vertex_count;
}

void	model3D_destroy(t_model3D *this)
{
	size_t	i;

	if (this != NULL)
	{
		i = 0;
		while (i < this->vertex_count)
			free(this->vertices[i++]);
		free(this->vertices);
	}
}

void	model3D_delete(t_model3D *this)
{
	if (this != NULL)
	{
		model3D_destroy(this);
		free(this);
	}
}
