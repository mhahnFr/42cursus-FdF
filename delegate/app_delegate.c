#include "mlx.h"

#include "app_delegate.h"

int		onApplicationFinishedLaunching(t_model3D *model, void *view)
{
	t_window	*main_window;

	main_window = delegate_get_new_window(view, 200, 50, "FdF");
	mlx_key_hook(view, delegate_key_touched, main_window);
	mlx_loop(view);
	model3D_delete(model);
	return (0);
}

t_window	*delegate_get_new_window(
				void *mlx_ptr,
			   	int width,
			   	int height,
				char *title)
{
	return (window_new(mlx_ptr, width, height, title));
}

int			delegate_key_touched(void *window)
{
	delegate_exit((t_window *) window);
	return (0);
}

void		delegate_exit(t_window *window)
{
	window_delete(window);
}
