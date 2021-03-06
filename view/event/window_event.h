#ifndef WINDOW_EVENT_H
# define WINDOW_EVENT_H

# include "window_event_type.h"

typedef struct s_window	t_window;

/*
 * Represents a window event. Consists of the affected window, the type of the
 * event, as well as a pointer to a nested event.
 */
typedef struct s_window_event
{
	t_window			*window;
	t_window_event_type	type;
	void				*nested;
	void				*pay_load;
}	t_window_event;

/*
 * Creates a new window event with the given affected window and the given
 * type. Returns the newly allocated window event, or null if either no
 * affected window is given or the allocation failed.
 */
t_window_event	*window_event_new(
					t_window *window,
					t_window_event_type type,
					void *pay_load);

/*
 * Initializes the content of the given window event.
 */
void			window_event_create(
					t_window_event *this,
					t_window *window,
					t_window_event_type type,
					void *pay_load);

/*
 * Destroys the content of the given window event. Does not attempt to free the
 * given object. Does nothing if no object is given.
 */
void			window_event_destroy(t_window_event *this);

/*
 * Deletes the given window event. Does nothing if no object is given.
 */
void			window_event_delete(t_window_event *this);

#endif
