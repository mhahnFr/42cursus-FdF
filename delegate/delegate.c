#include <stdlib.h>

#include "app_delegate.h"

t_delegate	*delegate_new(void *mlx_ptr, t_model3D *model, t_cli *cli_obj)
{
	t_delegate	*ret;

	if (mlx_ptr == NULL || model == NULL || cli_obj == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_delegate));
	if (ret != NULL)
		delegate_create(ret, mlx_ptr, model, cli_obj);
	return (ret);
}

void	delegate_create(
			t_delegate *this,
			void *mlx_ptr,
			t_model3D *model,
			t_cli *cli_obj)
{
	if (this != NULL)
	{
		this->mlx_ptr = mlx_ptr;
		this->model = model;
		this->cli_obj = cli_obj;
	}
}

void	delegate_destroy(t_delegate *this)
{
	if (this != NULL)
	{
		window_destroy(this->windows);
		model3D_destroy(this->model);
		cli_destroy(this->cli_obj);
		renderer_destroy(this->renderer);
	}
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
