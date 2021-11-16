#include <math.h>

#include "renderer.h"
#include "utils/math/matrix.h"

t_matrix	*renderer_generate_projection(
				t_renderer *this,
				float near,
				float far)
{
	t_matrix	*ret;
	float		w;
	float		h;

	if (this == NULL)
		return (NULL);
	ret = matrix_new_filled(0, 4, 4);
	if (ret == NULL)
		return (NULL);
	h = 1 / tan(30);
	w = h / (this->screen_width / this->screen_height);
	ret->values[0][0] = w;
	ret->values[1][1] = h;
	ret->values[2][2] = far / (near - far);
	ret->values[2][3] = -1;
	ret->values[3][2] = (near * far) / (near - far);
	return (ret);
}

t_matrix	*renderer_generate_projection_ort(
				t_renderer *this,
				float near,
				float far)
{
	t_matrix	*ret;
	float		w;
	float		h;

	if (this == NULL)
		return (NULL);
	ret = matrix_new_filled(0, 4, 4);
	if (ret == NULL)
		return (NULL);
	h = 1 / tan(30);
	w = h / (this->screen_width / this->screen_height);
	ret->values[0][0] = 2.0 / w;
	ret->values[1][1] = 2.0 / h;
	ret->values[2][2] = 1.0 / (near - far);
	ret->values[2][3] = -1;
	ret->values[3][2] = near / (near - far);
	return (ret);
}

t_matrix	*renderer_generate_view(t_renderer *this)
{
	t_matrix	*ret;
	t_vector	zaxis;
	t_vector	yaxis;
	t_vector	xaxis;

	if (this == NULL)
		return (NULL);
	ret = matrix_new_filled(0, 4, 4);
	if (ret == NULL)
		return (NULL);
	matrix_fill_neutral(ret);
	vector_substract(&zaxis, this->camera->pos, this->camera->view_point);
	vector_normalize(&zaxis);
	vector_multiply(&xaxis, this->camera->up, &zaxis);
	vector_normalize(&xaxis);
	vector_multiply(&yaxis, &zaxis, &xaxis);
	ret->values[0][0] = xaxis.x;
	ret->values[1][0] = xaxis.y;
	ret->values[2][0] = xaxis.z;
	ret->values[3][0] = -vector_scalar_product(&xaxis, this->camera->pos);
	ret->values[0][1] = yaxis.x;
	ret->values[1][1] = yaxis.y;
	ret->values[2][1] = yaxis.z;
	ret->values[3][1] = -vector_scalar_product(&yaxis, this->camera->pos);
	ret->values[0][2] = zaxis.x;
	ret->values[1][2] = zaxis.y;
	ret->values[2][2] = zaxis.z;
	ret->values[3][2] = -vector_scalar_product(&zaxis, this->camera->pos);
	return (ret);
}

void	renderer_generate_point(
			t_renderer *this,
			t_vertex3D *result,
			t_vertex3D *point)
{
	result->x = (1.0 + point->x) * this->buffer->width / 2.0;
	result->y = (1.0 + point->y) * this->buffer->height / 2.0;
	// TODO save min/max z values!!!
	result->z = 0.1 + point->z * (100 - 0.1);
}
