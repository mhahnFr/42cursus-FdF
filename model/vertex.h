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
 * Frees the given vertex.
 */
void		vertex3D_delete(t_vertex3D *this);

#endif
