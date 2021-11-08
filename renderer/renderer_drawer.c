#include <stddef.h>

#include "mlx.h"

#include "renderer.h"
#include "delegate/app_delegate.h"

void	renderer_draw(t_delegate *this)
{
	t_vertex3D	v_tmp;
	t_vertex3D	*prev;
	t_matrix	*m_tmp;
	t_matrix	*m_tmp2;
	size_t		i;

	prev = NULL;
	i = 0;
	while (i < this->model->vertex_count)
	{
		m_tmp2 = vertex3D_cast_matrix(this->model->vertices[i]);
		m_tmp = matrix_new_multiply(this->renderer->mvp, m_tmp2);
		matrix_delete(m_tmp2);
		matrix_cast_vertex3D(m_tmp, &v_tmp);
		matrix_delete(m_tmp);
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
	int	err;
	int	step_x;
	int	step_y;

	err = (second->x - first->x) + (second->y - first->y);
	step_x = renderer_get_step(first->x, second->x);
	step_y = renderer_get_step(first->y, second->y);
	while (1)
	{
		renderer_draw_point(first, buf);
		if (first->x == second->x && first->y == second->y)
			break ;
		if (err * 2 > second->y - first->y)
		{
			err += second->y - first->y;
			first->x += step_x;
		}
		if (err * 2 < second->x - first->x)
		{
			err += second->x - first->x;
			first->y += step_y;
		}
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

void	renderer_draw_line1(
			t_vertex3D *first,
			t_vertex3D *second,
			t_delegate *this)
{
	t_renderer_image	*buf;
	char				*dst;

	buf = this->renderer->buffer;
	if (first->x * -1 <= buf->width && first->y * -1 <= buf->height)
	{
		dst = buf->raw + (((long) first->x) * -1 * (buf->depth / 8))
			+ (((long) first->y) * -1 * buf->line_size);
		*(unsigned int *) dst = 0x00FFFFFF;
	}
	if (second->x * -1 <= buf->width && second->y * -1 <= buf->height)
	{
		dst = buf->raw + (((long) second->x) * -1 * (buf->depth / 8))
			+ (((long) second->y) * -1 * buf->line_size);
		*(unsigned int *) dst = 0x00FFFFFF;
	}
}
