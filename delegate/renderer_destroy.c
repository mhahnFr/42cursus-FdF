#include <stdlib.h>

#include "renderer.h"

void	renderer_destroy(t_renderer __attribute__((unused)) *this)
{
}

void	renderer_delete(t_renderer *this)
{
	renderer_destroy(this);
	if (this != NULL)
		free(this);
}
