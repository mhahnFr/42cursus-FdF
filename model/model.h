#ifndef MODEL_H
# define MODEL_H

# include "vertex.h"

/*
 * Represents a whole three dimensional model. Consists of a two dimensional
 * array with vertices and an array with the corresponding lengths. The length
 * of the count array is also present.
 */
typedef struct s_model3D
{
	t_vertex3D	***vertices;
	size_t		*vertex_count;
	size_t		vertex_count_length;
}	t_model3D;

/*
 * Creates a new three dimensional model using the given vertices. Returns
 * either the newly allocated model or null if either the allocation failed or
 * at least one parameter is missing.
 */
t_model3D	*model3D_new(
				size_t *vertices_count_ar,
				size_t vertices_count_length,
				t_vertex3D ***vertices);

/*
 * Initializes the given model with the given vertices. Does nothing if no
 * model or no vertices are given or no count array is given.
 */
void		model3D_create(
				t_model3D *this,
				size_t *vertices_count_ar,
				size_t vertices_count_length,
				t_vertex3D ***vertices);

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
