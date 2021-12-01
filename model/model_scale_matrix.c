#include "model.h"
#include "utils/math/matrix.h"
#include "utils/math/vector.h"

void	model3D_scale_matrix(t_model3D *this)
{
	if (this == NULL)
		return ;
	this->scale->values[0][0] = this->scaler->x;
	this->scale->values[1][1] = this->scaler->y;
	this->scale->values[2][2] = this->scaler->z;
}
