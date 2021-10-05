#include <stdlib.h>

#include "app_delegate.h"

t_delegate	*delegate_new(void *mlx_ptr, t_model3D *model, t_cli *cli_obj)
{
	t_delegate	*ret;

	if (mlx_ptr == NULL || model == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_delegate));
	if (ret != NULL)
	{
		ret->mlx_ptr = mlx_ptr;
		ret->model = model;
		ret->cli_obj = cli_obj;
	}
	return (ret);
}

void	delegate_delete(t_delegate *this)
{
	if (this != NULL)
	{
		window_delete(this->windows);
		model3D_delete(this->model);
		cli_delete(this->cli_obj);
		renderer_delete(this->renderer);
		free(this);
	}
}
