#include "utils/math/matrix.h"
#include "model.h"

void	model3D_multiply_matrices(t_model3D *this, t_matrix *result)
{
	t_matrix	*tmp;

	if (this == NULL || result == NULL)
		return ;
	matrix_fill(result, 0);
	tmp = matrix_new_multiply(this->movements, this->rotation_x);
	matrix_multiply(result, tmp, this->rotation_y);
	matrix_fill(tmp, 0);
	matrix_multiply(tmp, result, this->rotation_z);
	matrix_fill(result, 0);
	matrix_multiply(result, tmp, this->scale);
	matrix_delete(tmp);
}
