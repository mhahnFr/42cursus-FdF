#include "mlx.h"

#include "app_delegate.h"

int		onApplicationFinishedLaunching(t_model3D *model, void *view)
{
	t_window	*main_window;

	main_window = delegate_get_new_window(view, 200, 50, "FdF");
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
