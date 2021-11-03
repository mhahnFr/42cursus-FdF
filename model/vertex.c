#include <stdlib.h>

#include "vertex.h"
#include "utils/math/matrix.h"

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
		this->w = 1;
	}
}

t_matrix	*vertex3D_cast_matrix(t_vertex3D *this)
{
	t_matrix	*ret;

	ret = matrix_new(NULL, 4, 1);
	if (ret == NULL)
		return (NULL);
	ret->values[0][0] = this->x;
	ret->values[1][0] = this->y;
	ret->values[2][0] = this->z;
	ret->values[3][0] = this->w;
	return (ret);
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
