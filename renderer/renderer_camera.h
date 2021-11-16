#ifndef RENDERER_CAMERA_H
# define RENDERER_CAMERA_H

# include "utils/math/vector.h"
# include "model/vertex.h"

/*
 * Represents a camera. Its position should be in regular world coordinates.
 */
typedef struct s_renderer_camera
{
	t_vector	*pos;
	t_vector	*view_point;
	t_vector	*up;
}	t_renderer_camera;

/*
 * Allocates a new camera object with the given position. Returns either the
 * newly allocated camera or null, if either the allocation failed or no
 * position is given.
 */
t_renderer_camera	*renderer_camera_new(t_vector *position);

/*
 * Initializes the given camera object using the given position. Does nothing,
 * if at least one object is missing.
 */
void				renderer_camera_create(
						t_renderer_camera *this,
						t_vector *position);

/*
 * Destroys the given camera object. Does nothing if no object is given.
 */
void				renderer_camera_destroy(t_renderer_camera *this);

/*
 * Deletes the given camera object. Does nothing if n o object is given.
 */
void				renderer_camera_delete(t_renderer_camera *this);

#endif
