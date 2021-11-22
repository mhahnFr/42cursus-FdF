#include <stdlib.h>

#include "vertex.h"
#include "utils/math/matrix.h"

t_vertex3D	*vertex3D_new(float x, float y, float z)
{
	t_vertex3D	*ret;

	ret = malloc(sizeof(struct s_vertex3D));
	if (ret != NULL)
		vertex3D_create(ret, x, y, z);
	return (ret);
}

void	vertex3D_create(t_vertex3D *this, float x, float y, float z)
{
	if (this == NULL)
		return ;
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 1;
	this->r = 1;
	this->g = 1;
	this->b = 1;
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
