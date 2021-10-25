#ifndef RENDERER_H
# define RENDERER_H

/*
 * Represents a renderer.
 */
typedef struct s_renderer
{
	char	*text;
}	t_renderer;

/*
 * Represents a function that renders a frame. It is called in a loop by the
 * MiniLibX library, which passes a void pointer as payload. Returns an int,
 * whose value is totally ignored according to the documentation of the
 * MiniLibX library.
 */
typedef int (*t_render_frame)(void *);

/*
 * Represents a function that is called when the view in which the MiniLibX
 * draws, is initially displayed. It should prepare everything to be rendered.
 * Gets as parameter a void pointer that the MiniLibX library passes as
 * payload. Returns an int, whose value is totally ignored according to the
 * documentation of the MiniLibX library.
 */
typedef int (*t_pre_render)(void *);

/*
 * Creates a new renderer. Returns the newly allocated renderer, or null, if
 * the allocation failed.
 */
t_renderer	*renderer_new(void);

/*
 * Initializes the content of the given renderer object. Does nothing if no
 * object is given.
 */
void		renderer_create(t_renderer *this);

/*
 * Destroys the content of the given renderer object. Does nothing if no object
 * is given.
 */
void		renderer_destroy(t_renderer *this);

/*
 * Deletes the given renderer. Does nothing if no object is given.
 */
void		renderer_delete(t_renderer *this);

#endif
