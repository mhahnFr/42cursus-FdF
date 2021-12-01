#ifndef KEY_EVENT_H
# define KEY_EVENT_H

# include "window_event.h"
# include "key_codes.h"

/*
 * Represents a key event. Key events happen when the user presses a key.
 * Contains the key code.
 */
typedef struct s_key_event
{
	t_key_codes	key;
}	t_key_event;

/*
 * Creates a window event including a key event. Takes as parameters the key
 * code as well as the window and an optional payload. Returns the newly
 * allocated window event including a newly allocated nested key event. Returns
 * null if either the allocation failed or no window is given.
 */
t_window_event	*key_event_new(int key, t_window *window, void *pay_load);

/*
 * Creates a window event based on the given parameters. The key event should
 * simply be empty and from the stack. Returns the window event from the stack.
 */
t_window_event	key_event_create(
					t_key_event *this,
					int key,
					t_window *window,
					void *pay_load);

/*
 * Destroys the content of the given key event. Does nothing if no object is
 * given.
 */
void			key_event_destroy(t_key_event *this);

/*
 * Deletes the given key event. Does nothing if no event is given.
 */
void			key_event_delete(t_key_event *this);

/*
 * Destroys the given window event which has to contain a key event. Does
 * nothing if no event is given.
 */
void			key_event_super_destroy(t_window_event *event);

/*
 * Deletes the given window event which has to contain a key event. Does
 * nothing if no event is given. Assumes that the nested key event has been
 * allocated.
 */
void			key_event_super_delete(t_window_event *event);

#endif
