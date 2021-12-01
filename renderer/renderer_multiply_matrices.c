#include "renderer.h"

void	renderer_multiply_matrices(t_renderer *this)
{
	t_matrix	*tmp;

	if (this == NULL || this->model == NULL || this->view == NULL
		|| this->projection == NULL || this->mvp == NULL)
		return ;
	matrix_fill(this->mvp, 0);
	tmp = matrix_new_multiply(this->model, this->view);
	matrix_multiply(this->mvp, tmp, this->projection);
	matrix_delete(tmp);
}
