#ifndef APP_DELEGATE_H
# define APP_DELEGATE_H

# include "model/model.h"
# include "view/window.h"
# include "CLI/cli.h"

/*
 * Represents a delegate object. Consists of the window, the MLX connection and
 * the model.
 */
typedef struct s_delegate {
	t_window	*windows;
	void		*mlx_ptr;
	t_model3D	*model;
	t_cli		*cli_obj;
}	t_delegate;

/*
 * The starting point of the delegate. It controls whatever happens in this
 * application. Takes a pointer to the model and a pointer to the view of the
 * application. Returns the exit status of the program. Therefore, this
 * function should return control to the caller once the user quits the app.
 */
int			onApplicationFinishedLaunching(
				t_model3D *model,
				void *view,
				t_cli *cli_obj);

/*
 * Creates and returns a new window with the given size and the given title.
 */
t_window	*delegate_get_new_window(
				void *mlx_ptr,
				int width,
				int height,
				char *title);

/*
 * Delegates the event of a pressed key to the window on which it happened.
 * Tkaes as arguments the code of the pressed key and a pointer to the affected
 * window. Returns always zero, as the return value is useless according to the
 * documentation of the MiniLibX library.
 */
int			delegate_key_touched(int key, void *window);

/*
 * Handles the key events for the main window. Takes as parameter the
 * informations of the event.
 */
void		delegate_main_window_key_touched(
				t_window_event *w_event,
				t_key_event *k_event);

/*
 * Creates a new delegate object with the given MiniLibX connection pointer and
 * the model. Returns the newly allocated object, or null if either the
 * allocation failed or at least one parameter is missing.
 */
t_delegate	*delegate_new(void *mlx_ptr, t_model3D *model, t_cli *cli_obj);

/*
 * Deletes the given delegate object. Also removes all of its contents. Does
 * nothing if no object is given.
 */
void		delegate_delete(t_delegate *this);

/*
 * Closes the application.
 */
void		delegate_exit(t_delegate *this);

#endif
