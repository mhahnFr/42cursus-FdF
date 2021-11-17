#ifndef RENDERER_H
# define RENDERER_H

# include "utils/math/matrix.h"
# include "renderer_camera.h"
# include "renderer_image.h"

/*
 * Represents a renderer. Contains a matrix object for every possible
 * transformation, so there is a model, a view and a projection matrix. Also,
 * there is a combined matrix, as the matrices do not need to be recalculated
 * for every frame. The screen bounds are stored, a framebuffer is present, the
 * camera includes the view points and finally, there are the clipping
 * distances.
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
	float				near_z;
	float				far_z;
	t_renderer_camera	*camera;
	t_renderer_image	*buffer;
}	t_renderer;

typedef struct s_delegate	t_delegate;

typedef struct s_point		t_point;

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
 * Draws a line from the given point to the other one. They have to be screen
 * coordinates. Also takes the buffer image in which to draw the line.
 */
void		renderer_draw_line(
				t_point first,
				t_point second,
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
t_matrix	*renderer_generate_projection(t_renderer *this);

/*
 * Generates the values for the given vectors. The vectors are supposed to be
 * used for the projection matrix. Does nothing if at least one parameter is
 * missing.
 */
void		renderer_generate_proj_vectors(
				t_renderer *this,
				t_vector *xaxis,
				t_vector *yaxis,
				t_vector *zaxis);

/*
 * Performs the viewport transformation. Calculates a point on the screen based
 * on the values of the given renderer and the given point. Stores the result
 * in the given vertex object. Does nothing if at least one parameter is
 * missing.
 */
void		renderer_generate_point(
				t_renderer *this,
				t_vertex3D *result,
				t_vertex3D *point);

/*
 * Draws a point in the given image, if the point is on that image. The point
 * is an instance of vertex3D, only the X and the Y coordinates are used.
 * Crashes if wrong arguments are given.
 */
void		renderer_draw_point(t_point *point, t_renderer_image *buf);

/*
 * Modifies the given matrix in a way to perform a rotation araound the Z axis.
 * Does nothing if no matrix is given.
 */
void		renderer_rotate_matrix_z(t_matrix *rot, float angle);

/*
 * Modifies the given matrix in a way to perform a rotation around the Y axis.
 * Does nothing if no matrix is given.
 */
void		renderer_rotate_matrix_y(t_matrix *rot, float angle);

/*
 * Modifies the given matrix in a way to perform a rotation around the X axis.
 * Does nothing if no matrix is given.
 */
void		renderer_rotate_matrix_x(t_matrix *rot, float angle);

/*
 * Modifies the given matrix in a way to perform a translation with the values
 * of the given vector. Does nothing if no matrix or no vector is given.
 */
void		renderer_move_matrix(t_matrix *m, t_vector *vec);

/*
 * Returns wether the first number is bigger (-1) or not (1).
 */
long		renderer_sp(long first, long second);

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
