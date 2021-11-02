#include <stdlib.h>

#include "mlx.h"

#include "delegate/app_delegate.h"
#include "renderer.h"

int	delegate_render_frame(t_delegate *this)
{
	if (this == NULL)
		return (-1);
	mlx_clear_window(this->mlx_ptr, this->windows->mlx_window);
	if (this->renderer->text != NULL)
		mlx_string_put(
			this->mlx_ptr,
			this->windows->mlx_window,
			1,
			1,
			0x00FFFFFF,
			this->renderer->text);
	return (0);
}

int	delegate_pre_render(t_delegate *this)
{
	t_matrix	*mv;

	if (this == NULL)
		return (-1);
	this->renderer->camera->width = vector_new(1, 0, 0);
	this->renderer->camera->height = vector_new(0, 1, 0);
	this->renderer->camera->depth = vector_new(0, 0, 1);
	this->renderer->model = matrix_new(NULL, 4, 4);
	matrix_fill_neutral(this->renderer->model);
	this->renderer->view = renderer_generate_view(this->renderer);
	this->renderer->projection = renderer_generate_projection(this->renderer);
	mv = matrix_new_multiply(this->renderer->model, this->renderer->view);
	this->renderer->mvp = matrix_new_multiply(mv, this->renderer->projection);
	matrix_delete(mv);
	mlx_clear_window(this->mlx_ptr, this->windows->mlx_window);
	return (0);
}

t_renderer	*renderer_new(t_renderer_camera *camera)
{
	t_renderer			*ret;

	ret = malloc(sizeof(struct s_renderer));
	if (ret == NULL)
		return (NULL);
	renderer_create(ret, camera);
	return (ret);
}

void	renderer_create(t_renderer *this, t_renderer_camera *camera)
{
	if (this == NULL)
		return ;
	this->text = NULL;
	this->camera = camera;
}
