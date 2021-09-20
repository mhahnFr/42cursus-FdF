#include <stdlib.h>

#include "vertex.h"

t_vertex3D	*vertex3D_new(double x, double y, double z)
{
	t_vertex3D	*n;

	n = malloc(sizeof(struct s_vertex3D));
	if (n != NULL)
	{
		n->x = x;
		n->y = y;
		n->z = z;
	}
	return (n);
}

void		vertex3D_delete(t_vertex3D *this)
{
	if (this != NULL)
		free(this);
}

