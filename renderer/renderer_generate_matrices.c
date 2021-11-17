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

void	renderer_set_view(t_renderer *this)
{
	t_vector	xaxis;
	t_vector	yaxis;
	t_vector	zaxis;

	if (this == NULL || this->view == NULL)
		return ;
	matrix_fill_neutral(this->view);
	renderer_generate_proj_vectors(this, &xaxis, &yaxis, &zaxis);
	this->view->values[0][0] = xaxis.x;
	this->view->values[1][0] = xaxis.y;
	this->view->values[2][0] = xaxis.z;
	this->view->values[3][0] = -vector_scalar_product(&xaxis, this->camera->pos);
	this->view->values[0][1] = yaxis.x;
	this->view->values[1][1] = yaxis.y;
	this->view->values[2][1] = yaxis.z;
	this->view->values[3][1] = -vector_scalar_product(&yaxis, this->camera->pos);
	this->view->values[0][2] = zaxis.x;
	this->view->values[1][2] = zaxis.y;
	this->view->values[2][2] = zaxis.z;
	this->view->values[3][2] = -vector_scalar_product(&zaxis, this->camera->pos);
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
