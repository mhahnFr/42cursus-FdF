#include <stdlib.h>

#include "mlx.h"

#include "renderer.h"

void	renderer_destroy(t_renderer *this)
{
	if (this == NULL)
		return ;
	matrix_destroy(this->model);
	matrix_destroy(this->view);
	matrix_destroy(this->projection);
	matrix_destroy(this->mvp);
	renderer_camera_destroy(this->camera);
	renderer_image_destroy(this->buffer);
}

void	renderer_delete(t_renderer *this)
{
	if (this == NULL)
		return ;
	renderer_destroy(this);
	matrix_delete(this->model);
	matrix_delete(this->view);
	matrix_delete(this->projection);
	matrix_delete(this->mvp);
	renderer_camera_delete(this->camera);
	renderer_image_delete(this->buffer);
	free(this);
}
