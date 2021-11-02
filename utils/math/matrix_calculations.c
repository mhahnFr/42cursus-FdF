#include <stddef.h>

#include "matrix.h"

t_matrix	*matrix_new_multiply(t_matrix *m1, t_matrix *m2)
{
	t_matrix		*result;

	if (m1 == NULL || m2 == NULL || m1->columns != m2->rows)
		return (NULL);
	result = matrix_new(NULL, m1->rows, m2->columns);
	if (result == NULL)
		return (NULL);
	matrix_fill(result, 0);
	matrix_multiply(result, m1, m2);
	return (result);
}

void	matrix_multiply(t_matrix *result, t_matrix *m1, t_matrix *m2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (result == NULL || m1 == NULL || m2 == NULL || m1->columns != m2->rows
		|| result->rows != m1->rows || result->columns != m2->columns)
		return ;
	i = 0;
	while (i < m1->rows)
	{
		j = 0;
		while (j < m2->columns)
		{
			k = 0;
			while (k < m1->columns)
			{
				result->values[i][j] += m1->values[i][k] * m2->values[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}
