#include <stdlib.h>

#include "mlx.h"

#include "ft_printf.h"

#include "app_delegate.h"
#include "view/event/key_codes.h"

int	onApplicationFinishedLaunching(t_model3D *model, void *view, t_cli *cli_obj)
{
	t_delegate	*this;

	this = delegate_new(view, model, cli_obj);
	if (cli_obj->size_set)
		this->windows = delegate_get_new_window(view, cli_obj->width,
				cli_obj->height, "FdF");
	else
		this->windows = delegate_get_new_window(view, 200, 50, "FdF");
	mlx_key_hook(
		this->windows->mlx_window,
		(t_delegate_key_touched) delegate_key_touched,
		this);
	window_set_key_listener(
		this->windows, key_listener_new(delegate_main_window_key_touched));
	this->renderer = renderer_new(renderer_camera_new(vertex3D_new(0, 0, 0)));
	if (this->renderer == NULL)
		delegate_exit(this);
	mlx_expose_hook(
		this->windows->mlx_window,
		(t_pre_render) delegate_pre_render,
		this);
	mlx_loop_hook(view, (t_render_frame) delegate_render_frame, this);
	mlx_loop(view);
	return (0);
}

void	delegate_main_window_key_touched(
			t_window_event *w_event,
			t_key_event *k_event)
{
	if (k_event->key == ESC)
		delegate_exit((t_delegate *) w_event->pay_load);
	else if (k_event->key == H)
		((t_delegate *) w_event->pay_load)->renderer->text = "Hello World!";
	else if (k_event->key == FOUR || k_event->key == NUM_4)
		((t_delegate *) w_event->pay_load)->renderer->text = "42 Heilbronn";
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

int	delegate_key_touched(int key, t_delegate *this)
{
	t_window_event	*event;

	event = key_event_new(key, this->windows, this);
	window_pump_event(event);
	key_event_super_delete(event);
	return (0);
}

void	delegate_exit(t_delegate *this)
{
	mlx_loop_hook(this->mlx_ptr, NULL, NULL);
	delegate_delete(this);
	while (1);
	exit(0);
}
