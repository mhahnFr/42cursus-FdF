#ifndef VECTOR_H
# define VECTOR_H

/*
 * Represents a vector with three dimensions.
 */
typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

/*
 * Allocates a new vector with the given values. Returns either the newly
 * allocated vector or null if the allocation failed.
 */
t_vector	*vector_new(float x, float y, float z);

/*
 * Initializes the given vector with the given values. Does nothing if no
 * vector is given.
 */
void		vector_create(t_vector *this, float x, float y, float z);

/*
 * Claculates the scalar product of the given vectors. Returns either the
 * calculated result or zero, if at least one vector is missing.
 */
float		vector_scalar_product(t_vector *first, t_vector *second);

/*
 * Destroys the given vector. Does nothing if no vector is given.
 */
void		vector_destroy(t_vector *this);

/*
 * Deletes the given vector. Does nothing if no vector is given.
 */
void		vector_delete(t_vector *this);

#endif
