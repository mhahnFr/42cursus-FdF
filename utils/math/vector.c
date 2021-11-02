#include <stdlib.h>

#include "vector.h"

t_vector	*vector_new(float x, float y, float z)
{
	t_vector	*ret;

	ret = malloc(sizeof(struct s_vector));
	if (ret != NULL)
		vector_create(ret, x, y, z);
	return (ret);
}

void	vector_create(t_vector *this, float x, float y, float z)
{
	if (this == NULL)
		return ;
	this->x = x;
	this->y = y;
	this->z = z;
}

float	vector_scalar_product(t_vector *one, t_vector *two)
{
	if (one == NULL || two == NULL)
		return (0);
	return (one->x * two->x + one->y * two->y + one->z * two->z);
}
