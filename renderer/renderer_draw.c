#include <stdbool.h>
#include <math.h>

#include "mlx.h"

#include "renderer.h"
#include "delegate/app_delegate.h"
#include "model/vertex.h"
#include "utils/math/vector.h"
#include "utils/point.h"
#include "utils/math/abs.h"

void	renderer_draw(t_delegate *this)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < this->model->vertex_count_length)
	{
		j = 0;
		while (j < this->model->vertex_count[i])
		{
			renderer_draw_core(this->renderer, this->model, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(this->mlx_ptr, this->windows->mlx_window,
		this->renderer->buffer->mlx_img, 0, 0);
}

void	renderer_draw_line(
			t_point *start,
			t_point one,
			t_point two,
			t_renderer_image *buf)
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
		renderer_draw_coloured_point(&one, start, &two, buf);
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

#include <stdlib.h>
void	renderer_draw_core(
			t_renderer *this,
			t_model3D *model,
			size_t i,
			size_t j)
{
	t_vertex3D	v_tmp;
	t_point		cur;
	t_point		tmp;

	matrix_multiply_vertex3D(&v_tmp, this->mvp, model->vertices[i][j]);
	if (!v_tmp.colour_set) {
		int colour = rand();
		v_tmp.r = colour >> 16;
		v_tmp.g = colour >> 8;
		v_tmp.b = colour >> 0;
	}
	renderer_generate_point(this, &v_tmp, &v_tmp);
	vertex3D_cast_point(&v_tmp, &cur);
	if (j < model->vertex_count[i] - 1)
	{
		matrix_multiply_vertex3D(&v_tmp, this->mvp, model->vertices[i][j + 1]);
		if (!v_tmp.colour_set) {
			int colour = rand();
			v_tmp.r = colour >> 16;
			v_tmp.g = colour >> 8;
			v_tmp.b = colour >> 0;
		}
		renderer_generate_point(this, &v_tmp, &v_tmp);
		vertex3D_cast_point(&v_tmp, &tmp);
		renderer_draw_line(&cur, cur, tmp, this->buffer);
	}
	if (i < model->vertex_count_length - 1 && j < model->vertex_count[i + 1])
	{
		matrix_multiply_vertex3D(&v_tmp, this->mvp, model->vertices[i + 1][j]);
		if (!v_tmp.colour_set) {
			int colour = rand();
			v_tmp.r = colour >> 16;
			v_tmp.g = colour >> 8;
			v_tmp.b = colour >> 0;
		}
		renderer_generate_point(this, &v_tmp, &v_tmp);
		vertex3D_cast_point(&v_tmp, &tmp);
		renderer_draw_line(&cur, cur, tmp, this->buffer);
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
