#include <stdlib.h>

#include "model.h"

t_model3D	*model3D_new(t_arraylist *vertices)
{
	t_model3D	*n;

	n = malloc(sizeof(struct s_model3D));
	if (n != NULL)
	{
		n->vertices = (t_vertex3D **) arraylist_to_array(vertices);
		n->vertex_count = arraylist_size(vertices);
	}
	return (n);
}

void	model3D_delete(t_model3D *this)
{
	size_t	i;

	if (this != NULL)
	{
		i = 0;
		while (i < this->vertex_count)
			free(this->vertices[i++]);
		free(this->vertices);
		free(this);
	}
}
