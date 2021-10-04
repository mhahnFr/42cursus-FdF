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
 * code as well as the window. Returns the newly allocated window event
 * including a newly allocated nested key event. Returns null if either the
 * allocation failed or no window is given.
 */
t_window_event	*key_event_new(int key, t_window *window);

/*
 * Deletes the given key event. Does nothing if no event is given.
 */
void			key_event_delete(t_key_event *this);

/*
 * Destroys the given window event which has to contain a key event. Does
 * nothing if no event is given.
 */
void			key_event_destroy(t_window_event *event);

#endif
