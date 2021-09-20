#ifndef MODEL_H
# define MODEL_H

typedef struct s_model3D
{

} t_model3D;

/*
 * Creates a new three dimensional model. Returns the newly allocated model,
 * null in case of error.
 */
t_model3D	*model3D_new();

/*
 * Frees the given three dimensional model.
 */
void		model3D_delete(t_model3D *this);

#endif

