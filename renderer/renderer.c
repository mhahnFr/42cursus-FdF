#include <stdlib.h>

#include "mlx.h"

#include "delegate/app_delegate.h"
#include "renderer.h"

int	delegate_render_frame(t_delegate **this)
{
	if (this == NULL || *this == NULL)
		return (-1);
	mlx_clear_window((*this)->mlx_ptr, (*this)->windows->mlx_window);
	renderer_draw(*this);
	if ((*this)->renderer->text != NULL)
		mlx_string_put(
			(*this)->mlx_ptr,
			(*this)->windows->mlx_window,
			1,
			1,
			0x00FFFFFF,
			(*this)->renderer->text);
	return (0);
}

int	delegate_pre_render(t_delegate **this)
{
	t_matrix	*mv;

	if (this == NULL || *this == NULL)
		return (-1);
	(*this)->renderer->camera->view_point = vector_new(10, 10, 10);
	(*this)->renderer->model = matrix_new(NULL, 4, 4);
	matrix_fill_neutral((*this)->renderer->model);
	renderer_rotate_matrix_z((*this)->renderer->model, 180);
	(*this)->renderer->view = renderer_generate_view((*this)->renderer);
	(*this)->renderer->near_z = 0.1;
	(*this)->renderer->far_z = 10;
	(*this)->renderer->projection = renderer_generate_projection(
			(*this)->renderer);
	mv = matrix_new_multiply((*this)->renderer->model,
			(*this)->renderer->view);
	(*this)->renderer->mvp = matrix_new_multiply(
			mv, (*this)->renderer->projection);
	matrix_delete(mv);
	(*this)->renderer->buffer = renderer_image_new((*this)->mlx_ptr,
			(*this)->renderer->screen_width, (*this)->renderer->screen_height);
	mlx_clear_window((*this)->mlx_ptr, (*this)->windows->mlx_window);
	return (0);
}

t_renderer	*renderer_new(
				t_renderer_camera *camera,
				size_t screen_width,
				size_t screen_height)
{
	t_renderer			*ret;

	ret = malloc(sizeof(struct s_renderer));
	if (ret == NULL)
		return (NULL);
	renderer_create(ret, camera, screen_width, screen_height);
	return (ret);
}

void	renderer_create(
			t_renderer *this,
			t_renderer_camera *camera,
			size_t screen_width,
			size_t screen_height)
{
	if (this == NULL)
		return ;
	this->text = NULL;
	this->camera = camera;
	this->screen_width = screen_width;
	this->screen_height = screen_height;
	this->model = NULL;
	this->view = NULL;
	this->projection = NULL;
	this->mvp = NULL;
	this->buffer = NULL;
}
