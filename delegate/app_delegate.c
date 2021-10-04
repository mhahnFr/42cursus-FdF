#include <stdlib.h>

#include "mlx.h"

#include "ft_printf.h"

#include "app_delegate.h"

int	onApplicationFinishedLaunching(t_model3D *model, void *view)
{
	t_window	*main_window;

	main_window = delegate_get_new_window(view, 200, 50, "FdF");
	mlx_pixel_put(view, main_window->mlx_window, 1, 1, 0xFFFFFFFF);
	mlx_key_hook(main_window->mlx_window, delegate_key_touched, main_window);
	window_set_key_listener(
		main_window, key_listener_new(delegate_main_window_key_touched));
	mlx_loop(view);
	model3D_delete(model);
	return (0);
}

void	delegate_main_window_key_touched(t_key_event *event)
{
	if (event->key == 53)
		delegate_exit();
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

int	delegate_key_touched(int key, void *window)
{
	t_window_event	*event;

	event = key_event_new(key, (t_window *) window);
	window_pump_event(event);
	key_event_destroy(event);
	return (0);
}

void	delegate_exit(void)
{
	exit(0);
}
