#include <stdlib.h>

#include "mlx.h"

#include "app_delegate.h"
#include "renderer.h"

void print_model(t_model3D*);
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
	print_model(this->model);
	return (0);
}

#include <stdio.h>
void	print_model(t_model3D *model)
{
	for (size_t i = 0; i < model->vertex_count; i++)
		printf("| %f %f %f |", model->vertices[i]->x, model->vertices[i]->y, model->vertices[i]->z);
		printf("\n");
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
