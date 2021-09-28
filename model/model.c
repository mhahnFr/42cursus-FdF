#include <stdlib.h>

#include "model.h"

t_model3D	*model3D_new(void)
{
	t_model3D	*n;

	n = malloc(sizeof(struct s_model3D));
	return (n);
}

void	model3D_delete(t_model3D *this)
{
	if (this != NULL)
		free(this);
}
