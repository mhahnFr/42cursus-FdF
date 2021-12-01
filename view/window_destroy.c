#include <stdlib.h>

#include "mlx.h"

#include "window.h"

void	window_destroy(t_window *this)
{
	if (this != NULL)
	{
		mlx_destroy_window(this->mlx_ptr, this->mlx_window);
		key_listener_destroy(this->key_listener);
	}
}

void	window_delete(t_window *this)
{
	if (this != NULL)
	{
		mlx_destroy_window(this->mlx_ptr, this->mlx_window);
		key_listener_delete(this->key_listener);
		free(this);
	}
}
