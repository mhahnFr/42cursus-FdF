#include <stddef.h>

#include "vertex.h"
#include "utils/point.h"
#include "utils/math/matrix.h"

t_matrix	*vertex3D_cast_matrix(t_vertex3D *this)
{
	t_matrix	*ret;

	ret = matrix_new(NULL, 4, 1);
	if (ret == NULL)
		return (NULL);
	ret->values[0][0] = this->x;
	ret->values[0][1] = this->y;
	ret->values[0][2] = this->z;
	ret->values[0][3] = this->w;
	return (ret);
}

t_point	*vertex3D_cast_new_point(t_vertex3D *this)
{
	t_point	*ret;

	if (this == NULL)
		return (NULL);
	ret = point_new(this->x, this->y);
	return (ret);
}

void	vertex3D_cast_point(t_vertex3D *this, t_point *point)
{
	if (this == NULL || point == NULL)
		return ;
	point_create(point, this->x, this->y);
}
