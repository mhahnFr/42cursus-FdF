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
		cli_obj->width = 800;
		cli_obj->height = 600;
	}
	this->windows = delegate_get_new_window(view, cli_obj->width,
			cli_obj->height, cli_obj->file);
	mlx_do_key_autorepeaton(view);
	mlx_key_hook(this->windows->mlx_window,
		(t_delegate_key_touched) delegate_key_touched, &this);
	window_set_key_listener(
		this->windows, key_listener_new(delegate_main_window_key_touched));
	this->renderer = renderer_new(renderer_camera_new(
				vector_new(0.6, 0.6, 0.3)), cli_obj->width, cli_obj->height);
	if (this->renderer == NULL)
		delegate_exit(&this);
	delegate_pre_render(&this);
	mlx_hook(this->windows->mlx_window, 17, 0L,
		(t_delegate_close) delegate_exit, &this);
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
				= "Rotate: W A S D R F; move: ARROWS NUM_0 NUM_1;"
				" toggle projection: P; zoom: NUM_+ & NUM_-;"
				" toggle camera/model manipulation: SPACE; exit: ESC";
		else
			(*((t_delegate **) w_event->pay_load))->renderer->text = NULL;
	}
	else if (k_event->key == RETURN) {
		t_delegate **this = w_event->pay_load;
		printf("Cam pos: %f %f %f\nCam vAt: %f %f %f\n", (*this)->renderer->camera->pos->x, (*this)->renderer->camera->pos->y, (*this)->renderer->camera->pos->z, (*this)->renderer->camera->view_point->x, (*this)->renderer->camera->view_point->y, (*this)->renderer->camera->view_point->z);
	}
	else
		delegate_main_window_key_touched_proj(
			*((t_delegate **) w_event->pay_load), k_event->key);
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
	delegate_delete(this);
	system("leaks fdf");
	exit(0);
}
