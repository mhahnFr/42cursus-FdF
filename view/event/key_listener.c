#include <stdlib.h>

#include "key_listener.h"

t_key_listener	*key_listener_new(t_key_pressed func)
{
	t_key_listener	*ret;

	ret = NULL;
	if (func != NULL)
	{
		ret = malloc(sizeof(struct s_key_listener));
		if (ret != NULL)
			key_listener_create(ret, func);
	}
	return (ret);
}

void	key_listener_create(t_key_listener *this, t_key_pressed func)
{
	if (this != NULL)
		this->window_key_pressed = func;
}

void	key_listener_destroy(t_key_listener __attribute__((unused)) *this)
{
}

void	key_listener_delete(t_key_listener *this)
{
	key_listener_destroy(this);
	if (this != NULL)
		free(this);
}
