#ifndef MODEL_H
# define MODEL_H

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
 * Creates a new three dimensional model using the given vertices. Returns
 * either the newly allocated model or null if either the allocation failed or
 * no vertices are given.
 */
t_model3D	*model3D_new(t_vertex3D **vertices, size_t vertex_count);

/*
 * Initializes the given model with the given vertices. Does nothing if no
 * model or no vertices are given.
 */
void		model3D_create(
				t_model3D *this,
				t_vertex3D **vertices,
				size_t vertex_count);

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
