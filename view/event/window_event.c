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
		window_event_create(ret, window, type, pay_load);
	return (ret);
}

void	window_event_create(
			t_window_event *this,
			t_window *window,
			t_window_event_type type,
			void *pay_load)
{
	if (this != NULL)
	{
		this->window = window;
		this->type = type;
		this->nested = NULL;
		this->pay_load = pay_load;
	}
}

void	window_event_destroy(t_window_event __attribute__((unused)) *this)
{
}

void	window_event_delete(t_window_event *this)
{
	window_event_destroy(this);
	if (this != NULL)
		free(this);
}
