#include <stdlib.h>

#include "renderer_camera.h"

t_renderer_camera	*renderer_camera_new(t_vector *position)
{
	t_renderer_camera	*ret;

	if (position == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_renderer_camera));
	if (ret != NULL)
		renderer_camera_create(ret, position);
	return (ret);
}

void	renderer_camera_create(t_renderer_camera *this, t_vector *position)
{
	if (this == NULL || position == NULL)
		return ;
	this->pos = position;
	this->view_point = NULL;
	this->up = vector_new(0, 1, 0);
}

void	renderer_camera_destroy(t_renderer_camera *this)
{
	if (this == NULL)
		return ;
	vector_destroy(this->pos);
	vector_destroy(this->view_point);
	vector_destroy(this->up);
}

void	renderer_camera_delete(t_renderer_camera *this)
{
	if (this == NULL)
		return ;
	vector_delete(this->pos);
	vector_delete(this->view_point);
	vector_delete(this->up);
	free(this);
}
