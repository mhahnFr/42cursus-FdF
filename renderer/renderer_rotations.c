#include <math.h>

#include "renderer.h"

void	renderer_rotate_matrix_z(t_matrix *rot, float angle)
{
	if (rot == NULL)
		return ;
	rot->values[0][0] = cos(angle);
	rot->values[0][1] = -sin(angle);
	rot->values[1][0] = sin(angle);
	rot->values[1][1] = cos(angle);
}

void	renderer_rotate_matrix_y(t_matrix *rot, float angle)
{
	if (rot == NULL)
		return ;
	rot->values[0][0] = cos(angle);
	rot->values[0][2] = sin(angle);
	rot->values[2][0] = -sin(angle);
	rot->values[2][2] = cos(angle);
}

void	renderer_rotate_matrix_x(t_matrix *rot, float angle)
{
	if (rot == NULL)
		return ;
	rot->values[1][1] = cos(angle);
	rot->values[1][2] = -sin(angle);
	rot->values[2][1] = sin(angle);
	rot->values[2][2] = cos(angle);
}
