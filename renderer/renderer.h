#ifndef RENDERER_H
# define RENDERER_H

# include "utils/math/matrix.h"
# include "renderer_camera.h"
# include "renderer_image.h"

/*
 * Represents a renderer. Contains a matrix object for every possible
 * transformation, so there is a model, a view and a projection matrix. Also,
 * there is a combined matrix, as the matrices do not need to be recalculated
 * for every frame.
 */
typedef struct s_renderer
{
	char				*text;
	t_matrix			*model;
	t_matrix			*view;
	t_matrix			*projection;
	t_matrix			*mvp;
	size_t				screen_width;
	size_t				screen_height;
	t_renderer_camera	*camera;
	t_renderer_image	*buffer;
}	t_renderer;

typedef struct s_delegate	t_delegate;

/*
 * Represents a function that renders a frame. It is called in a loop by the
 * MiniLibX library, which passes a void pointer as payload. Returns an int,
 * whose value is totally ignored according to the documentation of the
 * MiniLibX library.
 */
typedef int					(*t_render_frame)(void *);

/*
 * Represents a function that is called when the view in which the MiniLibX
 * draws, is initially displayed. It should prepare everything to be rendered.
 * Gets as parameter a void pointer that the MiniLibX library passes as
 * payload. Returns an int, whose value is totally ignored according to the
 * documentation of the MiniLibX library.
 */
typedef int					(*t_pre_render)(void *);

/*
 * Creates a new renderer with the given camera. Returns the newly allocated
 * renderer, or null, if the allocation failed.
 */
t_renderer	*renderer_new(
				t_renderer_camera *camera,
				size_t screen_width,
				size_t screen_height);

/*
 * Initializes the content of the given renderer object using the given camera.
 * Does nothing if at least one object is missing.
 */
void		renderer_create(
				t_renderer *this,
				t_renderer_camera *camera,
				size_t screen_width,
				size_t screen_height);

/*
 * Draws a frame to the buffer, the buffer is then put onto the screen. Takes
 * as parameter a delegate object with all necessary informations.
 */
void		renderer_draw(t_delegate *this);

/*
 * Draws a line from the given vertex to the other one. They have to be screen
 * coordinates. Also takes a delegate object with the needed informations.
 */
void		renderer_draw_line(
				t_vertex3D *first,
				t_vertex3D *second,
				t_renderer_image *buf);

/*
 * Generates an appopriate view matrix for the given renderer. Returns either
 * the newly allocated matrix or null, if the allocation failed or no renderer
 * is given.
 */
t_matrix	*renderer_generate_view(t_renderer *this);

/*
 * Generates an appopriate projection matrix for the given renderer. Returns
 * either the newly allocated matrix or null, if the allocation failed or no
 * renderer is given.
 */
t_matrix	*renderer_generate_projection(
				t_renderer *this,
				float near,
				float far);

/*
 * Stores the vector and the floating point value in the given float array.
 * Does nothing if no vector or no array is given.
 */
void		renderer_generate_append(float result[4], t_vector *vec, float z);

/*
 * Generates the vectors for the rendderer camera.
 */
void		renderer_generate_vectors(t_renderer_camera *camera);

/*
 * Generates the depth vector for the given camera. Returns either a newly
 * allocated vector or null if either the allocation failed or no camera is
 * given.
 */
t_vector	*renderer_generate_depth(t_renderer_camera *camera);

/*
 * Generates the right vector for the given camera. Returns either the newly
 * allocated vector or null if either the allocation failed or no camera is
 * given.
 */
t_vector	*renderer_generate_right(t_renderer_camera *camera);

/*
 * Generates the up vector for the given camera. Returns either the newly
 * allocated vector or null if either the allocation failed or no camera is
 * given.
 */
t_vector	*renderer_generate_up(t_renderer_camera *camera);

/*
 * Draws a point in the given image, if the point is on that image. The point
 * is an instance of vertex3D, only the X and the Y coordinates are used.
 * Crashes if wrong arguments are given.
 */
void		renderer_draw_point(t_vertex3D *point, t_renderer_image *buf);

/*
 * Adjusts the values for the loop of the Bresenham algorythm. Takes as
 * parameters the current point on the screen, the original difference between
 * the two points and the step to which to move to. Also takes the error value,
 * which determines when to step on the next pixel. Crashes if wrong input is
 * given.
 */
void		renderer_draw_loop_adjust(
				t_vertex3D *point,
				t_vertex3D *diff,
				t_vertex3D *step,
				int *err);

/*
 * Returns wether the first number is bigger (1) or not (-1).
 */
int			renderer_get_step(int first, int second);

/*
 * Destroys the content of the given renderer object and its contents. Does
 * nothing if no object is given.
 */
void		renderer_destroy(t_renderer *this);

/*
 * Deletes the given renderer. Frees its matrices. Does nothing if no object is
 * given.
 */
void		renderer_delete(t_renderer *this);

#endif
