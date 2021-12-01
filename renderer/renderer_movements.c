#include "renderer.h"

void	renderer_move_matrix(t_matrix *m, t_vector *vec)
{
	if (m == NULL || vec == NULL)
		return ;
	m->values[0][3] = vec->x;
	m->values[1][3] = vec->y;
	m->values[2][3] = vec->z;
}
