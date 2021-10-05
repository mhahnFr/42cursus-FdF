#include <stdlib.h>

#include "window_event.h"

t_window_event	*window_event_new(
					t_window *window,
					t_window_event_type type,
					void *pay_load)
{
	t_window_event	*ret;

	ret = malloc(sizeof(struct s_window_event));
	if (ret != NULL)
	{
		ret->window = window;
		ret->type = type;
		ret->nested = NULL;
		ret->pay_load = pay_load;
	}
	return (ret);
}

void	window_event_delete(t_window_event *this)
{
	if (this != NULL)
		free(this);
}
