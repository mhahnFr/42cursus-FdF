#include <stddef.h>
#include <math.h>

#include "renderer.h"

t_matrix	*renderer_generate_view(t_renderer *this)
{
	t_matrix	*ret;
	t_vector	xaxis, yaxis, zaxis;
	t_vector	camPos;
	t_vector	viewPoint;
	t_vector	up;

	ret = matrix_new(NULL, 4, 4);
	vector_create(&up, 0, 1, 0);
	vector_create(&camPos, this->camera->pos->x, this->camera->pos->y, this->camera->pos->z);
	vector_create(&viewPoint, this->camera->view_point->x, this->camera->view_point->y, this->camera->view_point->z);
	vector_substract(&zaxis, &camPos, &viewPoint);
	vector_normalize(&zaxis);
	vector_multiply(&xaxis, &up, &zaxis);
	vector_normalize(&xaxis);
	vector_multiply(&yaxis, &zaxis, &xaxis);
	ret->values[0][0] = xaxis.x;
	ret->values[1][0] = xaxis.y;
	ret->values[2][0] = xaxis.z;
	ret->values[3][0] = vector_scalar_product(&xaxis, &camPos) * -1;
	
	ret->values[0][1] = yaxis.x;
	ret->values[1][1] = yaxis.y;
	ret->values[2][1] = yaxis.z;
	ret->values[3][1] = vector_scalar_product(&yaxis, &camPos) * -1;

	ret->values[0][2] = zaxis.x;
	ret->values[1][2] = zaxis.y;
	ret->values[2][2] = zaxis.z;
	ret->values[3][2] = vector_scalar_product(&zaxis, &camPos) * -1;

	ret->values[0][3] = 0;
	ret->values[1][3] = 0;
	ret->values[2][3] = 0;
	ret->values[3][3] = 1;
	return (ret);
}

t_matrix	*renderer_generate_view1(t_renderer *this)
{
	t_matrix	*ret;
	t_vector	cam_pos;

	if (this == NULL || this->camera == NULL || this->camera->pos == NULL
		|| this->camera->view_point == NULL)
		return (NULL);
	vector_create(&cam_pos, this->camera->pos->x, this->camera->pos->y,
		this->camera->pos->z);
	renderer_generate_vectors(this->camera);
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
t_matrix	*renderer_generate_projection2(
				t_renderer *this,
				float near,
				float far)
{
	t_matrix	*ret;
	float		h, w;

	ret = matrix_new_filled(0, 4, 4);
	h = 1 / tan(30);
	w = h / (this->screen_width / this->screen_height);
	ret->values[0][0] = 2 / w;
	ret->values[1][1] = 2 / h;
	ret->values[2][2] = 1 / (near - far);
	ret->values[2][3] = -1;
	ret->values[3][2] = near / (near - far);
	return ret;
}
t_matrix	*renderer_generate_projection(
				t_renderer *this,
				float near,
				float far)
{
	t_matrix	*ret;
	float		h, w;

	ret = matrix_new_filled(0, 4, 4);
	h = 1 / tan(30);
	w = h / (this->screen_width / this->screen_height);
	ret->values[0][0] = w;
	ret->values[1][1] = h;
	ret->values[2][2] = far / (near - far);
	ret->values[2][3] = -1;
	ret->values[3][2] = (near * far) / (near - far);
	return ret;
}

t_matrix	*renderer_generate_projection1(
				t_renderer *this,
				float near,
				float far)
{
	t_matrix	*ret;
	float		ratio;
	float		phi;

	if (this == NULL)
		return (NULL);
	phi = 41;
	ratio = this->screen_width / this->screen_height;
	ret = matrix_new_filled(0, 4, 4);
	if (ret == NULL)
		return (NULL);
	ret->values[0][0] = 1 / (ratio * tan(phi / 2));
	ret->values[1][1] = 1 / (tan(phi / 2));
	ret->values[2][2] = far / (near - far);
	ret->values[2][3] = (near * far) / (near - far);
	ret->values[3][2] = -1; // 3 | 2 ?
	return (ret);
}
