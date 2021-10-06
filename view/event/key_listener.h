#ifndef KEY_LISTENER_H
# define KEY_LISTENER_H

# include "key_event.h"

typedef void	(*t_key_pressed)(t_window_event *, t_key_event *);

/*
 * Represents a key listener. The function can be called whenever an key event
 * takes place. The function should never be null.
 */
typedef struct s_key_listener
{
	t_key_pressed	window_key_pressed;
}	t_key_listener;

/*
 * Creates a new instance of a key listener using the given function pointer.
 * Returns the newly allocated listener or null, if either the allocation
 * failed or no function is given.
 */
t_key_listener	*key_listener_new(t_key_pressed func);

/*
 * Initializes the given key listener with the given parameters. Does nothing
 * if no object is given.
 */
void			key_listener_create(t_key_listener *this, t_key_pressed func);

/*
 * Destroys the content of the given key listener. Does nothing if no object is
 * given.
 */
void			key_listener_destroy(t_key_listener *this);

/*
 * Deletes the given key listener. Does nothing if no listener is given.
 */
void			key_listener_delete(t_key_listener *this);

#endif
