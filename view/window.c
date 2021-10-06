#include <stdlib.h>

#include "mlx.h"

#include "window.h"

t_window	*window_new(void *mlx_ptr, int width, int height, char *title)
{
	t_window	*ret;

	if (mlx_ptr == NULL || width < 0 || height < 0 || title == NULL)
		return (NULL);
	ret = malloc(sizeof(t_window));
	if (ret != NULL)
	{
		ret->mlx_ptr = mlx_ptr;
		ret->mlx_window = mlx_new_window(mlx_ptr, width, height, title);
		if (ret->mlx_window == NULL)
		{
			window_delete(ret);
			return (NULL);
		}
		ret->key_listener = NULL;
	}
	return (ret);
}

t_window	window_create(void *mlx_ptr, int width, int height, char *title)
{
	t_window	ret;

	ret = (t_window) {};
	if (mlx_ptr != NULL && width >= 0 && height >= 0 && title != NULL)
	{
		ret.mlx_ptr = mlx_ptr;
		ret.mlx_window = mlx_new_window(mlx_ptr, width, height, title);
		ret.key_listener = NULL;
		if (ret.mlx_window == NULL)
			window_destroy(&ret);
	}
	return (ret);
}

void	window_set_key_listener(t_window *this, t_key_listener *listener)
{
	if (this != NULL)
		this->key_listener = listener;
}

void	window_pump_key_event(t_window_event *main_event, t_key_event *event)
{
	if (main_event != NULL
		&& main_event->window->key_listener != NULL
		&& event != NULL)
		main_event->window->key_listener->window_key_pressed(
			main_event, event);
}

void	window_pump_event(t_window_event *event)
{
	if (event != NULL)
	{
		if (event->type == KEY_EVENT)
			window_pump_key_event(event, (t_key_event *) event->nested);
	}
}

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
