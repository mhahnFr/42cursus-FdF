#include <stdlib.h>

#include "vertex.h"

t_vertex3D	*vertex3D_new(double x, double y, double z)
{
	t_vertex3D	*ret;

	ret = malloc(sizeof(struct s_vertex3D));
	if (ret != NULL)
		vertex3D_create(ret, x, y, z);
	return (ret);
}

void	vertex3D_create(t_vertex3D *this, double x, double y, double z)
{
	if (this != NULL)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
}

void	vertex3D_destroy(t_vertex3D __attribute__((unused)) *this)
{
}

void	vertex3D_delete(t_vertex3D *this)
{
	vertex3D_destroy(this);
	if (this != NULL)
		free(this);
}
