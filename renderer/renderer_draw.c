#include <stdio.h>
#include <stdbool.h>

#include "mlx.h"

#include "renderer.h"
#include "delegate/app_delegate.h"
#include "model/vertex.h"
#include "utils/math/vector.h"
#include "utils/point.h"
#include "utils/math/abs.h"

void	renderer_draw(t_delegate *this)
{
	t_point		cur;
	t_point		tmp;
	t_vertex3D	v_tmp;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < this->model->vertex_count_length)
	{
		j = 0;
		while (j < this->model->vertex_count[i])
		{
			matrix_multiply_vertex3D(&v_tmp, this->renderer->mvp,
				this->model->vertices[i][j]);
			renderer_generate_point(this->renderer, &v_tmp, &v_tmp);
			vertex3D_cast_point(&v_tmp, &cur);
			if (j < this->model->vertex_count[i] - 1)
			{
				matrix_multiply_vertex3D(&v_tmp, this->renderer->mvp,
					this->model->vertices[i][j + 1]);
				renderer_generate_point(this->renderer, &v_tmp, &v_tmp);
				vertex3D_cast_point(&v_tmp, &tmp);
				renderer_draw_line(cur, tmp, this->renderer->buffer);
			}
			if (i < this->model->vertex_count_length - 1
				&& j < this->model->vertex_count[i + 1])
			{
				matrix_multiply_vertex3D(&v_tmp, this->renderer->mvp,
					this->model->vertices[i + 1][j]);
				renderer_generate_point(this->renderer, &v_tmp, &v_tmp);
				vertex3D_cast_point(&v_tmp, &tmp);
				renderer_draw_line(cur, tmp, this->renderer->buffer);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(this->mlx_ptr, this->windows->mlx_window,
		this->renderer->buffer->mlx_img, 0, 0);
}

void	renderer_draw_line(t_point one, t_point two, t_renderer_image *buf)
{
	t_point	diff;
	t_point	s;
	long	err;
	long	e2;

	point_create(&diff, labs(two.x - one.x), -labs(two.y - one.y));
	point_create(&s, renderer_sp(one.x, two.x), renderer_sp(one.y, two.y));
	err = diff.x + diff.y;
	while (1)
	{
		renderer_draw_point(&one, buf);
		if (one.x == two.x && one.y == two.y)
			break ;
		e2 = 2 * err;
		if (e2 > diff.y)
		{
			err += diff.y;
			one.x += s.x;
		}
		if (e2 < diff.x)
		{
			err += diff.x;
			one.y += s.y;
		}
	}
}

long	renderer_sp(long first, long second)
{
	if (first > second)
		return (-1);
	return (1);
}

void	renderer_draw_point(t_point *point, t_renderer_image *buf)
{
	char	*dst;

	if (point->x < (long) buf->width && point->x >= 0
		&& point->y < (long) buf->height && point->y >= 0)
	{
		dst = buf->raw + (long) point->x * (buf->depth / 8) + (long) point->y
			* buf->line_size;
		*(unsigned int *) dst = (0 << 24) + (point->r << 16) + (point->g << 8)
			+ (point->b << 0);
	}
}
