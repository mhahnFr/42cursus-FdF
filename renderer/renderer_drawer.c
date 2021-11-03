#include <stddef.h>

#include "renderer.h"
#include "delegate/app_delegate.h"

void	renderer_draw(t_delegate *this)
{
	t_vertex3D	*v_tmp;
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
		v_tmp = matrix_cast_vertex3D(m_tmp);
		matrix_delete(m_tmp);
		if (prev != NULL)
		{
			renderer_draw_line(prev, v_tmp, this);
			vertex3D_delete(prev);
		}
		prev = v_tmp;
		i++;
	}
	vertex3D_delete(prev);
}

void	renderer_draw_line(
			t_vertex3D *first,
			t_vertex3D *second,
			t_delegate *this)
{
	first = second;
	this = NULL;
}
