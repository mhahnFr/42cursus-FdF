#include <stddef.h>

#include "vertex.h"

t_vertex3D	*vertex3D_copy(t_vertex3D *this)
{
	if (this == NULL)
		return (NULL);
	return (vertex3D_new(this->x, this->y, this->z));
}

void	vertex3D_copy_values(t_vertex3D *this, t_vertex3D *new)
{
	if (this == NULL || new == NULL)
		return ;
	vertex3D_create(new, this->x, this->y, this->z);
}
