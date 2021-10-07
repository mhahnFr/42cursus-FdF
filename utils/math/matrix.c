#include <stdlib.h>

#include "matrix.h"

t_matrix	*matrix_new(void)
{
	t_matrix	*ret;

	ret = malloc(sizeof(struct s_matrix));
	if (ret != NULL)
		matrix_create(ret);
	return (ret);
}

void	matrix_create(t_matrix __attribute__((unused)) *this)
{
}

void	matrix_destroy(t_matrix __attribute__((unused)) *this)
{
}

void	matrix_delete(t_matrix *this)
{
	matrix_destroy(this);
	if (this != NULL)
		free(this);
}
