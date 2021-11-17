#include <math.h>

#include "renderer.h"
#include "utils/math/matrix.h"

void	renderer_set_perspective_projection(t_renderer *this)
{
	float	w;
	float	h;

	if (this == NULL || this->projection == NULL)
		return ;
	matrix_fill(this->projection, 0);
	h = 1 / tan(30);
	w = h / (this->screen_width / this->screen_height);
	this->projection->values[0][0] = w;
	this->projection->values[1][1] = h;
	this->projection->values[2][2] = this->far_z / (this->near_z - this->far_z);
	this->projection->values[2][3] = -1;
	this->projection->values[3][2]
		= (this->near_z * this->far_z) / (this->near_z - this->far_z);
}

void	renderer_set_orthogonal_projection(t_renderer *this)
{
	float	h;
	float	w;

	if (this == NULL || this->projection == NULL)
		return ;
	matrix_fill(this->projection, 0);
	h = 1 / tan(3);
	w = h / (this->screen_width / this->screen_height);
	this->projection->values[0][0] = 2.0 / w;
	this->projection->values[1][1] = 2.0 / h;
	this->projection->values[2][2] = 1.0 / (this->near_z - this->far_z);
	this->projection->values[2][3] = -1;
	this->projection->values[3][2]
		= this->near_z / (this->near_z - this->far_z);
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
	renderer_generate_proj_vectors(this, &xaxis, &yaxis, &zaxis);
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

void	renderer_generate_proj_vectors(
			t_renderer *this,
			t_vector *xaxis,
			t_vector *yaxis,
			t_vector *zaxis)
{
	if (this == NULL || xaxis == NULL || yaxis == NULL || zaxis == NULL)
		return ;
	vector_substract(zaxis, this->camera->pos, this->camera->view_point);
	vector_normalize(zaxis);
	vector_multiply(xaxis, this->camera->up, zaxis);
	vector_normalize(xaxis);
	vector_multiply(yaxis, zaxis, xaxis);
}
