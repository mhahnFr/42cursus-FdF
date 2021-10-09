#include <stddef.h>

#include "matrix.h"

t_matrix	*matrix_new_filled(
				float fill,
				unsigned int rows,
				unsigned int columns)
{
	t_matrix	*ret;

	ret = matrix_new(NULL, rows, columns);
	if (ret != NULL)
		matrix_fill(ret, fill);
	return (ret);
}

void	matrix_fill(t_matrix *this, float fill)
{
	if (this != NULL)
	{
		for (unsigned int i = 0; i < this->rows; i++)
			for (unsigned int j = 0; j < this->columns; j++)
				this->values[i][j] = fill;
	}
}
