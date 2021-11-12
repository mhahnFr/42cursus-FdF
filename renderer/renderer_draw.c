#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"

#include "renderer.h"
#include "delegate/app_delegate.h"
#include "model/vertex.h"
#include "utils/math/vector.h"
#include "utils/point.h"

void	renderer_draw(t_delegate *this)
{
	t_point cur;
	t_point tmp;

	for (size_t i = 0; i < this->model->vertex_count_length; i++) {
		for (size_t j = 0; j < this->model->vertex_count[i]; j++) {
			vertex3D_cast_point(this->model->vertices[i][j], &cur);
			vertex3D_cast_point(this->model->vertices[i][j], &tmp);
			renderer_draw_line(&cur, &tmp, this->renderer->buffer);
		}
	}
	mlx_put_image_to_window(this->mlx_ptr, this->windows->mlx_window,
		this->renderer->buffer->mlx_img, 0, 0);
}

void	renderer_draw_line(t_point *one, t_point *two, t_renderer_image *buf)
{
	t_point	diff;
	t_point	s;
	long	err;
	long	e2;

	point_create(&diff, labs(two->x - one->x), -labs(two->y - one->y));
	point_create(&s, renderer_sp(one->x, two->x), renderer_sp(one->y, two->y));
	err = diff.x + diff.y;
	while (1)
	{
		renderer_draw_point(one, buf);
		if (one->x == two->x && one->y == two->y)
			break ;
		e2 = 2 * err;
		if (e2 > diff.y)
		{
			err += diff.y;
			one->x += s.x;
		}
		if (e2 < diff.x)
		{
			err += diff.x;
			one->y += s.y;
		}
	}
}

long	renderer_sp(long first, long second)
{
	if (first > second)
		return (-1);
	return (1);
}

//void line(int x0, int y0, int x1, int y1, t_renderer_image *buf)
//{
//  int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
//  int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
//  int err = dx+dy, e2; /* error value e_xy */

//  while (1) {
//    renderer_draw_point(x0,y0, buf);
//    if (x0==x1 && y0==y1) break;
//    e2 = 2*err;
//    if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
//    if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
//  }
//}

void	renderer_draw_point(t_point *point, t_renderer_image *buf)
{
	char	*dst;

	if (point->x <= (long) buf->width && point->x >= 0
		&& point->y <= (long) buf->height && point->y >= 0)
	{
		dst = buf->raw + (long) point->x * (buf->depth / 8) + (long) point->y
			* buf->line_size;
		*(unsigned int *) dst = 0x00FFFFFF;
	}
}

t_matrix	*renderer_generate_projection(t_renderer *this, float near, float far)
{
	this = NULL;
	near = far;
	return NULL;
}

t_matrix *renderer_generate_view(t_renderer *this) {
	this = NULL;
	return NULL;
}
