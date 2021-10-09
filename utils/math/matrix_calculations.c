#include <stddef.h>

#include "matrix.h"

t_matrix	*matrix_new_multiply(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*result;

	if (m1->columns != m2->rows || m1 == NULL || m2 == NULL)
		return (NULL);
	result = matrix_new(NULL, m1->rows, m2->columns);
	if (result == NULL)
		return (NULL);
	for (unsigned int i = 0; i < m1->rows; i++)
		for (unsigned int j = 0; j < m2->columns; j++)
			for (unsigned int k = 0; k < m1->columns; k++)
				result->values[i][j] += m1->values[i][k] * m2->values[k][j];
	return (result);
}

void	matrix_multiply(t_matrix *result, t_matrix *m1, t_matrix *m2)
{
	if (m1->columns != m2->rows || result == NULL || m1 == NULL || m2 == NULL)
		return ;
	for (unsigned int i = 0; i < m1->rows; i++)
		for (unsigned int j = 0; i < m2->columns; j++)
			for (unsigned int k = 0; k < m1->columns; k++)
				result->values[i][j] += m1->values[i][k] * m2->values[k][j];
}
