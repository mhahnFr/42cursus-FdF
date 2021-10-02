#include <stdlib.h>

#include "mlx.h"

#include "window.h"

t_window	*window_new(void *mlx_ptr, int width, int height, char *title)
{
	t_window	*ret;

	if (mlx_ptr == NULL || width < 0 || height < 0 || title == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_window));
	if (ret != NULL)
	{
		ret->mlx_window = mlx_new_window(mlx_ptr, width, height, title);
		if (ret->mlx_window == NULL)
			return (NULL);
	}
	return (ret);
}

void	window_delete(t_window *this)
{
	if (this != NULL)
	{
		mlx_destroy_window(this->mlx_ptr, this->mlx_window);
		free(this);
	}
}
