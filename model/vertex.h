#ifndef VERTEX_H
# define VERTEX_H

/*
 * Represents a three dimensional vertex.
 */
typedef struct s_vertex3D
{
	double	x;
	double	y;
	double	z;
}	t_vertex3D;

/*
 * Allocates a new vertex with the given coordinates. Returns the newly
 * allocated vertex, null in case of error.
 */
t_vertex3D	*vertex3D_new(double x, double y, double z);

/*
 * Initializes the content of the given vertex object using the given
 * parameters. Does nothing if no object is given.
 */
void		vertex3D_create(t_vertex3D *this, double x, double y, double z);

/*
 * Allocates a new vertex containing the values of the given vertex. Returns
 * either the copy of the given vertex or null if the allocation failed or no
 * vertex is given.
 */
t_vertex3D	*vertex3D_copy(t_vertex3D *this);

/*
 * Copies the values of the given vertex in the other given vertex. Does
 * nothing if at least one vertex is missing.
 */
void		vertex3D_copy_values(t_vertex3D *this, t_vertex3D *new);

/*
 * Destroys the content of the given vertex object. Does nothing if no object
 * is given.
 */
void		vertex3D_destroy(t_vertex3D *this);

/*
 * Frees the given vertex.
 */
void		vertex3D_delete(t_vertex3D *this);

#endif
