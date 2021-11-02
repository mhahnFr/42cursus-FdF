#ifndef RENDERER_H
# define RENDERER_H

# include "utils/math/matrix.h"
# include "renderer_camera.h"

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
	t_renderer_camera	*camera;
}	t_renderer;

/*
 * Represents a function that renders a frame. It is called in a loop by the
 * MiniLibX library, which passes a void pointer as payload. Returns an int,
 * whose value is totally ignored according to the documentation of the
 * MiniLibX library.
 */
typedef int	(*t_render_frame)(void *);

/*
 * Represents a function that is called when the view in which the MiniLibX
 * draws, is initially displayed. It should prepare everything to be rendered.
 * Gets as parameter a void pointer that the MiniLibX library passes as
 * payload. Returns an int, whose value is totally ignored according to the
 * documentation of the MiniLibX library.
 */
typedef int	(*t_pre_render)(void *);

/*
 * Creates a new renderer with the given camera. Returns the newly allocated
 * renderer, or null, if the allocation failed.
 */
t_renderer	*renderer_new(t_renderer_camera *camera);

/*
 * Initializes the content of the given renderer object using the given camera.
 * Does nothing if at least one object is missing.
 */
void		renderer_create(t_renderer *this, t_renderer_camera *camera);

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
 * Stores the vector and the floating point value in the given float array.
 * Does nothing if no vector or no array is given.
 */
void		renderer_generate_append(float result[4], t_vector *vec, float z);

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
