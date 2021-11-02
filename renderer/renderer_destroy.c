#include <stdlib.h>

#include "renderer.h"

void	renderer_destroy(t_renderer *this)
{
	if (this == NULL)
		return ;
	matrix_destroy(this->model);
	matrix_destroy(this->view);
	matrix_destroy(this->projection);
	matrix_destroy(this->mvp);
}

void	renderer_delete(t_renderer *this)
{
	renderer_destroy(this);
	if (this != NULL)
		free(this);
}
