#include "ft_printf.h"

#include "app_delegate.h"
#include "renderer/renderer.h"
#include "view/event/key_codes.h"

void	delegate_rotate_camera(t_delegate *this, t_key_codes key)
{
	if (key == A)
		this->model->scaler->x -= 0.1;
	if (key == D)
		this->model->scaler->x += 0.1;
	if (key == S)
		this->model->scaler->y -= 0.1;
	if (key == W)
		this->model->scaler->y += 0.1;
	if (key == F)
		this->model->scaler->z -= 0.1;
	if (key == R)
		this->model->scaler->z += 0.1;
	model3D_scale_matrix(this->model);
	model3D_multiply_matrices(this->model, this->renderer->model);
	renderer_multiply_matrices(this->renderer);
}

void	delegate_rotate_model(t_delegate *this, t_key_codes key)
{
	if (key == W)
	{
		this->model->x_angle += 0.1;
		renderer_rotate_matrix_x(this->model->rotation_x, this->model->x_angle);
	}
	else if (key == S)
	{
		this->model->x_angle -= 0.1;
		renderer_rotate_matrix_x(this->model->rotation_x, this->model->x_angle);
	}
	else if (key == A)
	{
		this->model->y_angle -= 0.1;
		renderer_rotate_matrix_y(this->model->rotation_y, this->model->y_angle);
	}
	else
	{
		delegate_rotate_model_part2(this, key);
		return ;
	}
	model3D_multiply_matrices(this->model, this->renderer->model);
	renderer_multiply_matrices(this->renderer);
}

void	delegate_main_window_key_touched_WASD(
			t_delegate *this,
			t_key_codes key)
{
	if (this->move_camera)
		delegate_rotate_camera(this, key);
	else
		delegate_rotate_model(this, key);
	delegate_main_window_key_touched_zoom(this, key);
}

void	delegate_rotate_model_part2(t_delegate *this, t_key_codes key)
{
	if (key == D)
	{
		this->model->y_angle += 0.1;
		renderer_rotate_matrix_y(this->model->rotation_y, this->model->y_angle);
	}
	else if (key == R)
	{
		this->model->z_angle += 0.1;
		renderer_rotate_matrix_z(this->model->rotation_z, this->model->z_angle);
	}
	else if (key == F)
	{
		this->model->z_angle -= 0.1;
		renderer_rotate_matrix_z(this->model->rotation_z, this->model->z_angle);
	}
	model3D_multiply_matrices(this->model, this->renderer->model);
	renderer_multiply_matrices(this->renderer);
}
