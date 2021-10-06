#include <stdlib.h>

#include "key_event.h"

t_window_event	*key_event_new(int key, t_window *window, void *pay_load)
{
	t_window_event	*event;
	t_key_event		*ret;

	event = NULL;
	if (window != NULL)
	{
		event = window_event_new(window, KEY_EVENT, pay_load);
		if (event == NULL)
			return (NULL);
		ret = malloc(sizeof(struct s_key_event));
		if (ret == NULL)
			return (NULL);
		ret->key = key;
		event->nested = ret;
	}
	return (event);
}

t_window_event	key_event_create(
					t_key_event *this,
					int key,
					t_window *window,
					void *pay_load)
{
	t_window_event	event;

	event = (t_window_event) {};
	if (this != NULL && window != NULL)
	{
		window_event_create(&event, window, KEY_EVENT, pay_load);
		this->key = key;
		event.nested = this;
	}
	return (event);
}

void	key_event_destroy(t_key_event __attribute__((unused)) *this)
{
}

void	key_event_delete(t_key_event *this)
{
	key_event_destroy(this);
	if (this != NULL)
		free(this);
}

void	key_event_super_delete(t_window_event *event)
{
	if (event != NULL)
	{
		key_event_delete((t_key_event *) event->nested);
		window_event_delete(event);
	}
}

void	key_event_super_destroy(t_window_event *event)
{
	if (event != NULL)
	{
		key_event_destroy((t_key_event *) event->nested);
		window_event_destroy(event);
	}
}
