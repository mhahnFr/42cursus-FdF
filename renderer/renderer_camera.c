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
}

void	renderer_camera_destroy(t_renderer_camera *this)
{
	if (this == NULL)
		return ;
	vertex3D_destroy(this->pos);
}

void	renderer_camera_delete(t_renderer_camera *this)
{
	if (this == NULL)
		return ;
	vertex3D_delete(this->pos);
	free(this);
}
