#include <stdlib.h>

#include "mlx.h"

#include "app_delegate.h"
#include "renderer.h"

int		delegate_render_frame(void *this)
{
	if (this == NULL)
		return (-1);
	return (0);
}

int		delegate_pre_render(void *this)
{
	if (this == NULL)
		return (-1);
	return (0);
}

t_renderer	*renderer_new()
{
	t_renderer	*ret;

	ret = malloc(sizeof(struct s_renderer));
	return (ret);
}

void		renderer_delete(t_renderer *this)
{
	if (this != NULL)
		free(this);
}
