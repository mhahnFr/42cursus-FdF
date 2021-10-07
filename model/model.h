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
 * Initializes the content of the given model object using the given arraylist.
 * Calls the to_array method on the given arraylist. Does nothing if either
 * object is missing.
 */
void		model3D_create(t_model3D *this, t_arraylist *vertices);

/*
 * Destroys the content of the given model object. Frees the array containing
 * the vertices. Does nothing if no object is given.
 */
void		model3D_destroy(t_model3D *this);

/*
 * Frees the given three dimensional model.
 */
void		model3D_delete(t_model3D *this);

#endif
