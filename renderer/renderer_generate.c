#include <stddef.h>
#include <math.h>

#include "renderer.h"

t_matrix	*renderer_generate_view(t_renderer *this)
{
	t_matrix	*ret;
	t_vector	cam_pos;

	if (this == NULL)
		return (NULL);
	vector_create(&cam_pos, this->camera->pos->x, this->camera->pos->y,
		this->camera->pos->z);
	ret = matrix_new_filled(0, 4, 4);
	if (ret == NULL)
		return (NULL);
	renderer_generate_append(ret->values[0], this->camera->width,
		vector_scalar_product(this->camera->width, &cam_pos)
		* -1);
	renderer_generate_append(ret->values[1], this->camera->height,
		vector_scalar_product(this->camera->height, &cam_pos) * -1);
	ret->values[2][0] = this->camera->depth->x * -1;
	ret->values[2][1] = this->camera->depth->y * -1;
	ret->values[2][2] = this->camera->depth->z * -1;
	ret->values[2][3] = vector_scalar_product(this->camera->depth, &cam_pos);
	ret->values[3][3] = 1;
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

t_matrix	*renderer_generate_projection(
				t_renderer *this,
				float near,
				float far)
{
	t_matrix	*ret;
	float		ratio;
	float		phi;

	if (this == NULL)
		return (NULL);
	phi = 50;
	ratio = this->screen_width / this->screen_height;
	ret = matrix_new_filled(0, 4, 4);
	if (ret == NULL)
		return (NULL);
	ret->values[0][0] = 1 / (ratio * tan(phi / 2));
	ret->values[1][1] = 1 / (tan(phi / 2));
	ret->values[2][2] = far / (near - far);
	ret->values[3][2] = (near * far) / (near - far);
	ret->values[2][3] = -1;
	return (ret);
}
