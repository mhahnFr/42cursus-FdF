#include <stdlib.h>

#include "model.h"

t_model3D	*model3D_new(t_arraylist *vertices)
{
	t_model3D	*ret;

	ret = NULL;
	if (vertices != NULL)
	{
		ret = malloc(sizeof(struct s_model3D));
		if (ret != NULL)
			model3D_create(ret, vertices);
	}
	return (ret);
}

void	model3D_create(t_model3D *this, t_arraylist *vertices)
{
	if (this != NULL && vertices != NULL)
	{
		this->vertices = (t_vertex3D **) arraylist_to_array(
					vertices,
					(t_arraylist_dup) vertex3D_copy);
		this->vertex_count = arraylist_size(vertices);
	}
}

void	model3D_destroy(t_model3D *this)
{
	size_t	i;

	if (this != NULL)
	{
		i = 0;
		while (i < this->vertex_count)
			free(this->vertices[i++]);
		free(this->vertices);
	}
}

void	model3D_delete(t_model3D *this)
{
	if (this != NULL)
	{
		model3D_destroy(this);
		free(this);
	}
}
