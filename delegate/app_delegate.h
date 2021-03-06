#ifndef APP_DELEGATE_H
# define APP_DELEGATE_H

# include <stddef.h>
# include <stdbool.h>

# include "model/model.h"
# include "view/window.h"
# include "CLI/cli.h"
# include "renderer/renderer.h"

/*
 * Represents a delegate object. Consists of the window, the MLX connection and
 * the model.
 */
typedef struct s_delegate {
	t_window	*windows;
	void		*mlx_ptr;
	t_model3D	*model;
	t_cli		*cli_obj;
	t_renderer	*renderer;
	bool		move_camera;
}	t_delegate;

/*
 * Represents a function that gets called by the MiniLibX library, when a key
 * on the keyboard is pressed. Takes as parameter the key code and a void
 * pointer as payload. It returns an integer value, it is however ignored by
 * the MiniLibX library according to its documentation.
 */
typedef int	(*t_delegate_key_touched)(int, void *);

/*
 * A function that terminates the application properly.
 */
typedef int	(*t_delegate_close)(void *);

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
 * Takes as arguments the code of the pressed key and an object of the
 * responsible delegate. Returns always zero, as the return value is useless
 * according to the documentation of the MiniLibX library.
 */
int			delegate_key_touched(int key, t_delegate **this);

/*
 * Handles the key events for the main window. Takes as parameter the
 * informations of the event.
 */
void		delegate_main_window_key_touched(
				t_window_event *w_event,
				t_key_event *k_event);

/*
 * Handles the keys for changing the projection type.
 */
void		delegate_main_window_key_touched_proj(
				t_delegate *this,
				t_key_codes key);

/*
 * Handles the events of pressed arrow keys.
 */
void		delegate_main_window_key_touched_arrows(
				t_delegate *this,
				t_key_codes key);

/*
 * Moves the model according to the pressed key.
 */
void		delegate_move_model(t_delegate *this, t_key_codes key);

/*
 * Moves the camera according to the pressed key.
 */
void		delegate_move_camera(t_delegate *this, t_key_codes key);

/*
 * Moves the camera according to the pressed key.
 */
void		delegate_move_camera_part2(t_delegate *this, t_key_codes key);

/*
 * Rotates the camera according to the pressed key.
 */
void		delegate_rotate_camera(t_delegate *this, t_key_codes key);

/*
 * Rotates the model according to the pressed key.
 */
void		delegate_rotate_model(t_delegate *this, t_key_codes key);

/*
 * Rotates the model according to the pressed key.
 */
void		delegate_rotate_model_part2(t_delegate *this, t_key_codes key);

/*
 * Handles the events of a pressed W A S D key.
 */
void		delegate_main_window_key_touched_WASD(
				t_delegate *this,
				t_key_codes key);

/*
 * Handles the event of a pressed key for zooming.
 */
void		delegate_main_window_key_touched_zoom(
				t_delegate *this,
				t_key_codes key);

/*
 * Handles the key event of toggling between camera and model manipulation.
 */
void		delegate_main_window_key_touched_toggle(
				t_delegate *this,
				t_key_codes key);

/*
 * Creates a new delegate object with the given MiniLibX connection pointer and
 * the model and the given command line interface. Returns the newly allocated
 * object, or null if either the allocation failed or at least one parameter is
 * missing.
 */
t_delegate	*delegate_new(void *mlx_ptr, t_model3D *model, t_cli *cli_obj);

/*
 * Initializes the given delegate object using the given parameters. Does
 * nothing if no object is given.
 */
void		delegate_create(
				t_delegate *this,
				void *mlx_ptr,
				t_model3D *model,
				t_cli *cli_obj);

/*
 * Destroys the content of the given delegate object. Does nothing if no object
 * is given.
 */
void		delegate_destroy(t_delegate *this);

/*
 * Deletes the given delegate object. Also removes all of its contents. Does
 * nothing if no object is given.
 */
void		delegate_delete(t_delegate **this);

/*
 * Closes the application.
 */
void		delegate_exit(t_delegate **this);

/*
 * This method renders a new frame. Whenever a new frame should be displayed,
 * this method should be called. Ideally do this in a loop or connect it with
 * the system, so that vertical syncronization is possible. Takes as parameter
 * a delegate. If no object is given, it will do nothing and returns -1.
 * Otherwise, it will render everything and returns zero.
 */
int			delegate_render_frame(t_delegate **this);

/*
 * Settles up all prerequisities to be able to start rendering. This method
 * should be called only one time before the render loop starts. Takes as
 * parameter a delegate object. If no object is given -1 will be returned and
 * nothing else happens. Otherwise, zero will be returned and the render
 * process is prepared.
 */
int			delegate_pre_render(t_delegate **this);

#endif
