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
	mlx_do_key_autorepeaton((*((t_delegate **) w_event->pay_load))->mlx_ptr);
	if (k_event->key == ESC)
		delegate_exit((t_delegate **) w_event->pay_load);
	else if (k_event->key == H)
		(*((t_delegate **) w_event->pay_load))->renderer->text = "Hello World!";
	else if (k_event->key == FOUR || k_event->key == NUM_4)
		(*((t_delegate **) w_event->pay_load))->renderer->text = "42 Heilbronn";
	else if (k_event->key == P)
	{
		renderer_set_perspective_projection(
			(*((t_delegate **) w_event->pay_load))->renderer);
		renderer_multiply_matrices(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == O)
	{
		renderer_set_orthogonal_projection(
			(*((t_delegate **) w_event->pay_load))->renderer);
		renderer_multiply_matrices(
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
		renderer_multiply_matrices(
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
		renderer_multiply_matrices(
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
		renderer_multiply_matrices(
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
		renderer_multiply_matrices(
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
		renderer_multiply_matrices(
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
		renderer_multiply_matrices(
			(*((t_delegate **) w_event->pay_load))->renderer);
	}
	else if (k_event->key == RETURN)
		printf("Camera position: %f %f %f\nView point: %f %f %f\n",
			(*((t_delegate **) w_event->pay_load))->renderer->camera->pos->x,
			(*((t_delegate **) w_event->pay_load))->renderer->camera->pos->y,
			(*((t_delegate **) w_event->pay_load))->renderer->camera->pos->z,
			(*((t_delegate **) w_event->pay_load))->renderer->camera
			->view_point->x,
			(*((t_delegate **) w_event->pay_load))->renderer->camera
			->view_point->y,
			(*((t_delegate **) w_event->pay_load))->renderer->camera
			->view_point->z);
	else
		ft_printf("Key pressed on main window: %d\n", k_event->key);
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
