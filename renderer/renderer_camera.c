#include <stdlib.h>

#include "renderer_camera.h"

t_renderer_camera	*renderer_camera_new(t_vertex3D *position)
{
	t_renderer_camera	*ret;

	if (position == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_renderer_camera));
	if (ret != NULL)
		renderer_camera_create(ret, position);
	return (ret);
}

void	renderer_camera_create(t_renderer_camera *this, t_vertex3D *position)
{
	if (this == NULL || position == NULL)
		return ;
	this->pos = position;
	this->depth = NULL;
	this->width = NULL;
	this->height = NULL;
}

void	renderer_camera_destroy(t_renderer_camera *this)
{
	if (this == NULL)
		return ;
	vertex3D_destroy(this->pos);
	vector_destroy(this->depth);
	vector_destroy(this->width);
	vector_destroy(this->height);
}

void	renderer_camera_delete(t_renderer_camera *this)
{
	if (this == NULL)
		return ;
	vertex3D_delete(this->pos);
	vector_delete(this->depth);
	vector_delete(this->width);
	vector_delete(this->height);
	free(this);
}
