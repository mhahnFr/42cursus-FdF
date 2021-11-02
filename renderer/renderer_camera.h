#ifndef RENDERER_CAMERA_H
# define RENDERER_CAMERA_H

# include "model/vertex.h"

/*
 * Represents a camera. Its position should be in regular world coordinates.
 */
typedef struct s_renderer_camera
{
	t_vertex3D	*pos;
}	t_renderer_camera;

/*
 * Allocates a new camera object with the given position. Returns either the
 * newly allocated camera or null, if either the allocation failed or no
 * position is given.
 */
t_renderer_camera	*renderer_camera_new(t_vertex3D *position);

/*
 * Initializes the given camera object using the given position. Does nothing,
 * if at least one object is missing.
 */
void				renderer_camera_create(
						t_renderer_camera *this,
						t_vertex3D *position);

/*
 * Destroys the given camera object. Does nothing if no object is given.
 */
void				renderer_camera_destroy(t_renderer_camera *this);

/*
 * Deletes the given camera object. Does nothing if n o object is given.
 */
void				renderer_camera_delete(t_renderer_camera *this);

#endif
