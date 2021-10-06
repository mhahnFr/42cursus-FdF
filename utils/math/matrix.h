#ifndef MATRIX_H
# define MATRIX_H

/*
 * Represents a mathematical matrix.
 */
typedef struct s_matrix {

}	t_matrix;

/*
 * Creates a new matrix object. Returns the newly allocated matrix object, null
 * if the allocation failed.
 */
t_matrix	*matrix_new();

/*
 * Initializes the given matrix object.
 */
void		matrix_create(t_matrix *this);

/*
 * Destroys the given matrix object. Does not attempt to free the given object,
 * this method only destroys the contents of the given object. Does nothing if
 * no object is given.
 */
void		matrix_destroy(t_matrix *this);

/*
 * Deletes the given matrix object. Does nothing if no object is given.
 */
void		matrix_delete(t_matrix *this);

#endif
