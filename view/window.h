#ifndef WINDOW_H
# define WINDOW_H

/*
 * Represents a window. Contains a pointer to the MLX representation, the width
 * and height of the window as well as its title and the MLX window identifier.
 */
typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_window;
	int		width;
	int		height;
	char	*title;
}	t_window;

/*
 * Creates a new MLX window with the given parameters.The MLX pointer is the 
 * reference to the MiniLibX library. Also takes the width and height as well
 * as the title of the window. Returns the newly allocated window, in case of
 * error or wrong input null is returned.
 */
t_window	*window_new(void *mlx_ptr, int width, int height, char *title);

/*
 * Deletes the given window. If no window is given, this method does nothing.
 */
void	window_dispose(t_window *this);

#endif
