#include <stdlib.h>

#include "mlx.h"

#include "ft_printf.h"

#include "app_delegate.h"
#include "view/event/key_codes.h"

int	onApplicationFinishedLaunching(t_model3D *model, void *view, t_cli *cli)
{
	t_delegate	*this;

	this = delegate_new(view, model);
	if (cli->size_set)
		this->windows = delegate_get_new_window(view, cli->width, cli->height,
			"FdF");
	else
		this->windows = delegate_get_new_window(view, 200, 50, "FdF");
	mlx_string_put(this->mlx_ptr, this->windows->mlx_window, 1, 1, 0x00FFFFFF,
		"Hello World!");
	mlx_key_hook(this->windows->mlx_window, delegate_key_touched, this);
	window_set_key_listener(
		this->windows, key_listener_new(delegate_main_window_key_touched));
	mlx_loop(view);
	return (0);
}

void	delegate_main_window_key_touched(t_key_event *event)
{
	if (event->key == ESC)
		delegate_exit(NULL); // TODO callback !!!
	else
		ft_printf("Key pressed on main window: %d\n", event->key);
}

t_window	*delegate_get_new_window(
				void *mlx_ptr,
			   	int width,
			   	int height,
				char *title)
{
	return (window_new(mlx_ptr, width, height, title));
}

int	delegate_key_touched(int key, void *this)
{
	t_window_event	*event;

	event = key_event_new(key, ((t_delegate *) this)->windows);
	window_pump_event(event);
	key_event_destroy(event);
	// Callback !!!
	return (0);
}

void	delegate_exit(t_delegate *this)
{
	delegate_delete(this);
	exit(0);
}
