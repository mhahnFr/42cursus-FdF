#ifndef APP_DELEGATE_H
# define APP_DELEGATE_H

# include "model/model.h"
# include "view/window.h"

/*
 * The starting point of the delegate. It controls whatever happens in this
 * application. Takes a pointer to the model and a pointer to the view of the
 * application. Returns the exit status of the program. Therefore, this
 * function should return control to the caller once the user quits the app.
 */
int		onApplicationFinishedLaunching(t_model3D *model, void *view);

/*
 * Creates and returns a new window with the given parameters.
 */
t_window	*delegate_get_new_window(
				void *mlx_ptr,
				int width,
				int height,
				char *title);

#endif
