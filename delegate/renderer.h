#ifndef RENDERER_H
# define RENDERER_H

/*
 * Represents a renderer.
 */
typedef struct s_renderer
{
}	t_renderer;

/*
 * Creates a new renderer. Returns the newly allocated renderer, or null, if
 * the allocation failed.
 */
t_renderer	*renderer_new(void);

/*
 * Deletes the given renderer. Does nothing if no object is given.
 */
void		renderer_delete(t_renderer *this);

#endif
