#include <stdlib.h>

#include "matrix.h"

t_matrix	*matrix_new(
				float **matrix,
				unsigned int rows,
				unsigned int columns)
{
	t_matrix		*ret;
	unsigned int	i;

	ret = malloc(sizeof(struct s_matrix));
	if (ret == NULL)
		return (NULL);
	if (matrix == NULL)
	{
		matrix = malloc(rows * sizeof(float *));
		i = 0;
		while (i < rows)
			matrix[i++] = malloc(columns * sizeof(float));
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
	unsigned int	i;

	matrix_destroy(this);
	if (this != NULL)
	{
		if (this->values != NULL)
		{
			i = 0;
			while (i < this->rows)
			{
				free(this->values[i]);
				i++;
			}
			free(this->values);
		}
		free(this);
	}
}
