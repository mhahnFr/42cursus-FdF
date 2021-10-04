#include <stdlib.h>

#include "key_listener.h"

t_key_listener	*key_listener_new(key_pressed func)
{
	t_key_listener	*ret;

	ret = NULL;
	if (func != NULL)
	{
		ret = malloc(sizeof(struct s_key_listener));
		if (ret != NULL)
			ret->window_key_pressed = func;
	}
	return (ret);
}

void	key_listener_delete(t_key_listener *this)
{
	if (this != NULL)
		free(this);
}
