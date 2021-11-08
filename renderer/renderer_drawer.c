#include <stddef.h>

#include "mlx.h"

#include "renderer.h"
#include "delegate/app_delegate.h"

#include <stdio.h>
void	renderer_draw(t_delegate *this)
{
	t_vertex3D	v_tmp;
	t_vertex3D	*prev;
	size_t		i;

	prev = NULL;
	i = 0;
	printf("\n");
	while (i < this->model->vertex_count)
	{
		matrix_multiply_vertex3D(
			&v_tmp, this->renderer->mvp, this->model->vertices[i]);
		printf("%f %f %f %f\n", v_tmp.x, v_tmp.y, v_tmp.z, v_tmp.w);
		if (prev != NULL)
			renderer_draw_line(prev, &v_tmp, this->renderer->buffer);
		prev = &v_tmp;
		i++;
	}
	mlx_put_image_to_window(this->mlx_ptr, this->windows->mlx_window,
		this->renderer->buffer->mlx_img, 0, 0);
}

void	renderer_draw_line(
			t_vertex3D *first,
			t_vertex3D *second,
			t_renderer_image *buf)
{
	t_vertex3D	step;
	t_vertex3D	diff;
	t_vertex3D	point;
	int			err;

	diff.x = second->x - first->x;
	diff.y = second->y - first->y;
	err = diff.x + diff.y;
	step.x = renderer_get_step(first->x, second->x);
	step.y = renderer_get_step(first->y, second->y);
	point.x = first->x;
	point.y = first->y;
	while (1)
	{
		renderer_draw_point(&point, buf);
		if (point.x == second->x && point.y == second->y)
			break ;
		renderer_draw_loop_adjust(&point, &diff, &step, &err);
	}
}

void	renderer_draw_loop_adjust(
			t_vertex3D *point,
			t_vertex3D *diff,
			t_vertex3D *step,
			int *err)
{
	if (*err * 2 > diff->y)
	{
		*err = *err + diff->y;
		point->x += step->x;
	}
	if (*err * 2 < diff->x)
	{
		*err = *err + diff->x;
		point->y += step->y;
	}
}

void	renderer_draw_point(t_vertex3D *point, t_renderer_image *buf)
{
	char	*dst;

	if (point->x <= buf->width && point->x >= 0)
	{
		dst = buf->raw + (long) point->x * (buf->depth / 8) + (long) point->y
			* buf->line_size;
		*(unsigned int *) dst = 0x00FFFFFF;
	}
}

int	renderer_get_step(int first, int second)
{
	if (first < second)
		return (1);
	else
		return (-1);
}
