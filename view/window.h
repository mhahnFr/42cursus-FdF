#ifndef WINDOW_H
# define WINDOW_H

# include "event/key_event.h"
# include "event/key_listener.h"

/*
 * Represents a window. Contains a pointer to the MLX representation, the width
 * and height of the window as well as its title and the MLX window identifier.
 * There are also pointers to the optional listeners.
 */
typedef struct s_window
{
	void			*mlx_ptr;
	void			*mlx_window;
	int				width;
	int				height;
	char			*title;
	t_key_listener	*key_listener;
}	t_window;

/*
 * Creates a new MLX window with the given parameters.The MLX pointer is the 
 * reference to the MiniLibX library. Also takes the width and height as well
 * as the title of the window. Returns the newly allocated window, in case of
 * error or wrong input null is returned.
 */
t_window	*window_new(void *mlx_ptr, int width, int height, char *title);

/*
 * Creates a new window object on the stack with the given parameters. Returns
 * the created window from the stack, if the parameters are invalid, null is
 * returned.
 */
t_window	window_create(void *mlx_ptr, int width, int height, char *title);

/*
 * Sets the key listener to the given one. If there was already one set on the
 * given window, it will be overwritten by the given one.
 */
void		window_set_key_listener(t_window *this, t_key_listener *listener);

/*
 * Pumps the given key event to the the registered listener of the given
 * window. If neither a window nor an event is given or there is no listener
 * registered on the given window, this method does nothing.
 */
void		window_pump_key_event(
				t_window_event *main_event,
				t_key_event *event);

/*
 * Pumps the given event to the appopriate method.
 */
void		window_pump_event(t_window_event *event);

/*
 * Destroys the content of the given window. If no window is given, this method
 * does nothing.
 */
void		window_destroy(t_window *this);

/*
 * Deletes the given window. If no window is given, this method does nothing.
 */
void		window_delete(t_window *this);

#endif
