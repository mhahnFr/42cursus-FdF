#ifndef MODEL_H
# define MODEL_H

# include "utils/arraylist.h"
# include "vertex.h"

/*
 * Represents a whole three dimensional model. Consists of some vertices.
 */
typedef struct s_model3D
{
	t_vertex3D	**vertices;
	size_t		vertex_count;
}	t_model3D;

/*
 * Creates a new three dimensional model using the vertices in the given
 * arraylist. Returns the newly allocated model or null if either the
 * allocation failed or no vertices are given.
 */
t_model3D	*model3D_new(t_arraylist *vertices);

/*
 * Frees the given three dimensional model.
 */
void		model3D_delete(t_model3D *this);

#endif
