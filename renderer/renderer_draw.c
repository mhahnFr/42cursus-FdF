#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"

#include "renderer.h"
#include "delegate/app_delegate.h"
#include "model/vertex.h"
#include "utils/math/vector.h"

void line(int, int, int, int, t_renderer_image*);
void my_line(t_vertex3D*,t_vertex3D*,t_renderer_image*);

void	renderer_draw(t_delegate *this)
{
	t_vertex3D	tmp;
	t_vertex3D	prev;

	printf("\n");
	for (size_t i = 0; i < this->model->vertex_count; i++) {
		//printf("%f %f %f %f\n", this->model->vertices[i]->x, 
		//	this->model->vertices[i]->y, this->model->vertices[i]->z,
		//	this->model->vertices[i]->w);
		vertex3D_create(&tmp, this->model->vertices[i]->x * 10, 
			this->model->vertices[i]->y * 10, this->model->vertices[i]->z * 10);
		if (i != 0) {
			renderer_draw_line(&prev, &tmp, this->renderer->buffer);
			vertex3D_create(&tmp, this->model->vertices[i - 1]->x, this->model->vertices[i - 1]->y,this->model->vertices[i - 1]->z);

		//	my_line(&prev, &tmp, this->renderer->buffer);
		}
		vertex3D_create(&prev, tmp.x, tmp.y, tmp.z);
	}
	mlx_put_image_to_window(this->mlx_ptr, this->windows->mlx_window,
		this->renderer->buffer->mlx_img, 0, 0);
}

void	renderer_draw_line(t_vertex3D *first, t_vertex3D *second, t_renderer_image *buf) {
	line(first->x, first->y, second->x, second->y, buf);
/*	int err, stepX, stepY;
	long firstX, firstY, secondX, secondY;

	firstX = first->x;
	firstY = first->y;
	secondX = second->x;
	secondY = second->y;
	err = labs(secondX - firstX) + -labs(secondY - firstY);
	stepX = firstX < secondX ? 1 : -1;
	stepY = firstY < secondY ? 1 : -1;
	size_t ctr = 0;
	printf("\n");
	while (true) {
		ctr++;
		printf("%zu\n", ctr);
		renderer_draw_point(firstX, firstY, buf);
		if (firstX == secondX && firstY == secondY)
			break ;
		if (err * 2 > secondY - firstY) {
			err += secondY - firstY;
			firstX += stepX;
		}
		if (err * 2 < secondX - firstX) {
			err += secondX - firstX;
			firstY += stepY;
		}
	}*/
}

void my_line(t_vertex3D *first, t_vertex3D *second, t_renderer_image *buf)
{
	long	dx, dy, sx, sy, err, e2;
	long	x0, x1, y0, y1;

	x0 = first->x;
	x1 = second->x;
	y0 = first->y;
	y1 = second->y;
	dx = labs(x1 - x0);
	dy = -labs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1) {
		renderer_draw_point(x0, y0, buf);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}
}

void line(int x0, int y0, int x1, int y1, t_renderer_image *buf)
{
  int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = dx+dy, e2; /* error value e_xy */

  while (1) {
    renderer_draw_point(x0,y0, buf);
    if (x0==x1 && y0==y1) break;
    e2 = 2*err;
    if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

void	renderer_draw_point(long pointX, long pointY, t_renderer_image *buf)
{
	char	*dst;

	if (pointX <= (long) buf->width && pointX >= 0
		&& pointY <= (long) buf->height && pointY >= 0)
	{
		dst = buf->raw + (long) pointX * (buf->depth / 8) + (long) pointY
			* buf->line_size;
		*(unsigned int *) dst = 0x00FFFFFF;
	}
//	printf("%f %f\n", point->x, point->y);
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
