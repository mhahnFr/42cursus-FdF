#include <stdlib.h>

#include "key_event.h"

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
