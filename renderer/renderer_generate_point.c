#include "renderer.h"
#include "model/vertex.h"

void	renderer_generate_point(
			t_renderer *this,
			t_vertex3D *result,
			t_vertex3D *point)
{
	if (this == NULL || result == NULL || point == NULL)
		return ;
	if (this->perspective)
	{
		result->x = this->factor * ((1.0 - point->x) * this->buffer->width / 2.0);
		result->y = this->factor * ((1.0 - point->y) * this->buffer->height / 2.0);
	}
	else
	{
		result->x = this->factor * ((1.0 + point->x) * this->buffer->width / 2.0);
		result->y = this->factor * ((1.0 + point->y) * this->buffer->height / 2.0);
	}
	result->z = this->near_z + point->z * (this->far_z - this->near_z);
	result->r = point->r;
	result->g = point->g;
	result->b = point->b;
}
