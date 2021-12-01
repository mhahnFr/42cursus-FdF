#ifndef POINT_H
# define POINT_H

/*
 * Represents a two dimensional point. Consists of the X and the Y value and
 * the colour values.
 */
typedef struct s_point {
	long			x;
	long			y;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_point;

/*
 * Allocates a new point with the given values. Returns either the newly
 * allocated point or null if the allocation failed.
 */
t_point	*point_new(long x, long y);

/*
 * Initializes the given point using the given values. Does nothing if no point
 * is given.
 */
void	point_create(t_point *this, long x, long y);

/*
 * Destroys the contents of the given point. Does nothing if no point is given.
 */
void	point_destroy(t_point *this);

/*
 * Deletes the given point. Does nothing if no point is given.
 */
void	point_delete(t_point *this);

#endif
