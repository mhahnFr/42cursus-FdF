#include <stdlib.h>

#include "mlx.h"

#include "app_delegate.h"
#include "renderer.h"

int	delegate_render_frame(t_delegate *this)
{
	if (this == NULL)
		return (-1);
	mlx_clear_window(this->mlx_ptr, this->windows->mlx_window);
	if (this->renderer->text != NULL)
		mlx_string_put(
			this->mlx_ptr,
			this->windows->mlx_window,
			1,
			1,
			0x00FFFFFF,
			this->renderer->text);
	return (0);
}

int	delegate_pre_render(t_delegate *this)
{
	if (this == NULL)
		return (-1);
	mlx_clear_window(this->mlx_ptr, this->windows->mlx_window);
	return (0);
}

t_renderer	*renderer_new(void)
{
	t_renderer	*ret;

	ret = malloc(sizeof(struct s_renderer));
	if (ret != NULL)
		renderer_create(ret);
	return (ret);
}

void	renderer_create(t_renderer *this)
{
	if (this != NULL)
		this->text = NULL;
}
