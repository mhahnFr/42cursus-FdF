#include <stddef.h>

#include "renderer.h"

t_matrix	*renderer_generate_view(t_renderer *this)
{
	t_matrix	*ret;
	t_vector	cam_pos;

	if (this == NULL)
		return (NULL);
	vector_create(&cam_pos, this->camera->pos->x, this->camera->pos->y,
		this->camera->pos->z);
	ret = matrix_new(NULL, 4, 4);
	renderer_generate_append(ret->values[0], this->camera->width,
		vector_scalar_product(this->camera->width, &cam_pos)
		* -1);
	renderer_generate_append(ret->values[1], this->camera->height,
		vector_scalar_product(this->camera->height, &cam_pos) * -1);
	ret->values[2][0] = this->camera->depth->x * -1;
	ret->values[2][1] = this->camera->depth->y * -1;
	ret->values[2][2] = this->camera->depth->z * -1;
	ret->values[2][3] = vector_scalar_product(this->camera->depth, &cam_pos);
	ret->values[3][0] = 0;
	ret->values[3][1] = 0;
	ret->values[3][2] = 0;
	ret->values[3][3] = 0;
	return (ret);
}

void	renderer_generate_append(float result[4], t_vector *vec, float z)
{
	if (result == NULL || vec == NULL)
		return ;
	result[0] = vec->x;
	result[1] = vec->y;
	result[2] = vec->z;
	result[3] = z;
}

t_matrix	*renderer_generate_projection(t_renderer *this)
{
	t_matrix	*ret;

	if (this == NULL)
		return (NULL);
	ret = NULL;
	return (ret);
}
