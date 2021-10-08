#include <stdlib.h>

#include "libft.h"

#include "matrix.h"

t_matrix	*matrix_new(
				float **matrix,
				unsigned int rows,
				unsigned int columns)
{
	t_matrix	*ret;

	ret = malloc(sizeof(struct s_matrix));
	if (ret == NULL)
		return (NULL);
	if (matrix == NULL)
	{
		// Fill matrix function!!!
		matrix = ft_calloc(rows, sizeof(float *));
		for (unsigned int i = 0; i < rows; i++)
			matrix[i] = ft_calloc(columns, sizeof(float));
		if (matrix == NULL)
			return (NULL);
	}
	matrix_create(ret, matrix, rows, columns);
	return (ret);
}

void	matrix_create(
			t_matrix *this,
			float **matrix,
			unsigned int rows,
			unsigned int columns)
{
	if (this != NULL)
	{
		this->values = matrix;
		this->rows = rows;
		this->columns = columns;
	}
}

void	matrix_destroy(t_matrix __attribute__((unused)) *this)
{
}

void	matrix_delete(t_matrix *this)
{
	matrix_destroy(this);
	if (this != NULL)
	{
		if (this->values != NULL)
			free(this->values);
		free(this);
	}
}
