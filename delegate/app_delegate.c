#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"

#include "ft_printf.h"

#include "app_delegate.h"
#include "view/event/key_codes.h"

int	onApplicationFinishedLaunching(t_model3D *model, void *view, t_cli *cli_obj)
{
	t_delegate	*this;

	this = delegate_new(view, model, cli_obj);
	if (!cli_obj->size_set)
	{
		cli_obj->width = 200;
		cli_obj->height = 50;
	}
	this->windows = delegate_get_new_window(view, cli_obj->width,
			cli_obj->height, cli_obj->file);
	mlx_do_key_autorepeaton(view);
	mlx_key_hook(this->windows->mlx_window,
		(t_delegate_key_touched) delegate_key_touched, &this);
	window_set_key_listener(
		this->windows, key_listener_new(delegate_main_window_key_touched));
	this->renderer = renderer_new(renderer_camera_new(
				vector_new(-100, -100, 100)), cli_obj->width, cli_obj->height);
	if (this->renderer == NULL)
		delegate_exit(&this);
	delegate_pre_render(&this);
	mlx_loop_hook(view, (t_render_frame) delegate_render_frame, &this);
	mlx_loop(view);
	return (0);
}

void	delegate_main_window_key_touched(
			t_window_event *w_event,
			t_key_event *k_event)
{
	if (k_event->key == ESC)
		delegate_exit((t_delegate **) w_event->pay_load);
	else if (k_event->key == H || k_event->key == F1)
	{
		if ((*((t_delegate **) w_event->pay_load))->renderer->text == NULL)
			(*((t_delegate **) w_event->pay_load))->renderer->text
				= "Rotate map: W A S D R F; move: ARROWS NUM_0 NUM_1;"
				" projection: O P; move map: NUM_4 - 9; zoom: NUM_+"
				" & NUM_-; exit: ESC";
		else
			(*((t_delegate **) w_event->pay_load))->renderer->text = NULL;
		return ;
	}
	else if (k_event->key == P)
	{
		renderer_set_perspective_projection(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == O)
	{
		renderer_set_orthogonal_projection(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == LEFT)
	{
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->pos->x -= 1;
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->view_point->x += 1;
		renderer_set_view(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == RIGHT)
	{
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->pos->x += 1;
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->view_point->x -= 1;
		renderer_set_view(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == UP)
	{
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->pos->y += 1;
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->view_point->y -= 1;
		renderer_set_view(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == DOWN)
	{
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->pos->y -= 1;
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->view_point->y += 1;
		renderer_set_view(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == NUM_1)
	{
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->pos->z += 1;
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->view_point->z -= 1;
		renderer_set_view(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == NUM_0)
	{
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->pos->z -= 1;
		(*((t_delegate **) w_event->pay_load))
			->renderer->camera->view_point->z += 1;
		renderer_set_view(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == W)
	{
		(*((t_delegate **) w_event->pay_load))->model->x_angle += 0.1;
		renderer_rotate_matrix_x(
			(*((t_delegate **) w_event->pay_load))->renderer->model,
			(*((t_delegate **) w_event->pay_load))->model->x_angle);
	}
	else if (k_event->key == S)
	{
		(*((t_delegate **) w_event->pay_load))->model->x_angle -= 0.1;
		renderer_rotate_matrix_x(
			(*((t_delegate **) w_event->pay_load))->renderer->model,
			(*((t_delegate **) w_event->pay_load))->model->x_angle);
	}
	else if (k_event->key == A)
	{
		(*((t_delegate **) w_event->pay_load))->model->y_angle -= 0.1;
		renderer_rotate_matrix_y(
			(*((t_delegate **) w_event->pay_load))->renderer->model,
			(*((t_delegate **) w_event->pay_load))->model->y_angle);
	}
	else if (k_event->key == D)
	{
		(*((t_delegate **) w_event->pay_load))->model->y_angle += 0.1;
		renderer_rotate_matrix_y(
			(*((t_delegate **) w_event->pay_load))->renderer->model,
			(*((t_delegate **) w_event->pay_load))->model->y_angle);
	}
	else if (k_event->key == R)
	{
		(*((t_delegate **) w_event->pay_load))->model->z_angle += 0.1;
		renderer_rotate_matrix_z(
			(*((t_delegate **) w_event->pay_load))->renderer->model,
			(*((t_delegate **) w_event->pay_load))->model->z_angle);
	}
	else if (k_event->key == F)
	{
		(*((t_delegate **) w_event->pay_load))->model->z_angle -= 0.1;
		renderer_rotate_matrix_z(
			(*((t_delegate **) w_event->pay_load))->renderer->model,
			(*((t_delegate **) w_event->pay_load))->model->z_angle);
	}
	else if (k_event->key == NUM_4)
	{
		(*((t_delegate **) w_event->pay_load))->model->mover->x -= 0.1;
		renderer_move_matrix((*((t_delegate **) w_event->pay_load))->renderer
			->model, (*((t_delegate **) w_event->pay_load))->model->mover);
	}
	else if (k_event->key == NUM_6)
	{
		(*((t_delegate **) w_event->pay_load))->model->mover->x += 0.1;
		renderer_move_matrix((*((t_delegate **) w_event->pay_load))->renderer
			->model, (*((t_delegate **) w_event->pay_load))->model->mover);
	}
	else if (k_event->key == NUM_5)
	{
		(*((t_delegate **) w_event->pay_load))->model->mover->y -= 0.1;
		renderer_move_matrix((*((t_delegate **) w_event->pay_load))->renderer
			->model, (*((t_delegate **) w_event->pay_load))->model->mover);
	}
	else if (k_event->key == NUM_8)
	{
		(*((t_delegate **) w_event->pay_load))->model->mover->y += 0.1;
		renderer_move_matrix((*((t_delegate **) w_event->pay_load))->renderer
			->model, (*((t_delegate **) w_event->pay_load))->model->mover);
	}
	else if (k_event->key == NUM_7)
	{
		(*((t_delegate **) w_event->pay_load))->model->mover->z -= 0.1;
		renderer_move_matrix((*((t_delegate **) w_event->pay_load))->renderer
			->model, (*((t_delegate **) w_event->pay_load))->model->mover);
	}
	else if (k_event->key == NUM_9)
	{
		(*((t_delegate **) w_event->pay_load))->model->mover->z += 0.1;
		renderer_move_matrix((*((t_delegate **) w_event->pay_load))->renderer
			->model, (*((t_delegate **) w_event->pay_load))->model->mover);
	}
	else if (k_event->key == NUM_PLUS)
		ft_printf("TODO: zoom in\n");
	else if (k_event->key == NUM_MINUS)
		ft_printf("TODO: zoom out\n");
	else if (k_event->key == RETURN)
	{
		printf("Cam pos: %f %f %f\nView point: %f %f %f\nAngles: %f %f %f\n",
			(*((t_delegate **) w_event->pay_load))->renderer->camera->pos->x,
			(*((t_delegate **) w_event->pay_load))->renderer->camera->pos->y,
			(*((t_delegate **) w_event->pay_load))->renderer->camera->pos->z,
			(*((t_delegate **) w_event->pay_load))->renderer->camera
			->view_point->x,
			(*((t_delegate **) w_event->pay_load))->renderer->camera
			->view_point->y,
			(*((t_delegate **) w_event->pay_load))->renderer->camera
			->view_point->z,
			(*((t_delegate **) w_event->pay_load))->model->x_angle,
			(*((t_delegate **) w_event->pay_load))->model->y_angle,
			(*((t_delegate **) w_event->pay_load))->model->z_angle);
		return ;
	}
	else
		return ;
	renderer_multiply_matrices(
		(*((t_delegate **) w_event->pay_load))->renderer);
}

t_window	*delegate_get_new_window(
				void *mlx_ptr,
			   	int width,
			   	int height,
				char *title)
{
	return (window_new(mlx_ptr, width, height, title));
}

int	delegate_key_touched(int key, t_delegate **this)
{
	t_window_event	*event;

	event = key_event_new(key, (*this)->windows, this);
	window_pump_event(event);
	key_event_super_delete(event);
	return (0);
}

void	delegate_exit(t_delegate **this)
{
	// TODO Exit application when closing the window!!!
	delegate_delete(this);
	system("leaks fdf");
	exit(0);
}
