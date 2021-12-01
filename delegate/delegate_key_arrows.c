#include "app_delegate.h"
#include "renderer/renderer.h"
#include "view/event/key_codes.h"

void	delegate_main_window_key_touched_arrows(
			t_delegate *this,
			t_key_codes key)
{
	if (this->move_camera)
		delegate_move_camera(this, key);
	else
		delegate_move_model(this, key);
	delegate_main_window_key_touched_WASD(this, key);
}

void	delegate_move_model(t_delegate *this, t_key_codes key)
{
	if (key == LEFT)
		this->model->mover->x -= 0.1;
	else if (key == RIGHT)
		this->model->mover->x += 0.1;
	else if (key == DOWN)
		this->model->mover->y -= 0.1;
	else if (key == UP)
		this->model->mover->y += 0.1;
	else if (key == NUM_0)
		this->model->mover->z -= 0.1;
	else if (key == NUM_1)
		this->model->mover->z += 0.1;
	renderer_move_matrix(this->model->movements, this->model->mover);
	model3D_multiply_matrices(this->model, this->renderer->model);
	renderer_multiply_matrices(this->renderer);
}

void	delegate_move_camera(t_delegate *this, t_key_codes key)
{
	if (key == LEFT)
	{
		this->renderer->camera->pos->x -= 0.1;
		this->renderer->camera->view_point->x += 0.1;
	}
	else if (key == RIGHT)
	{
		this->renderer->camera->pos->x += 0.1;
		this->renderer->camera->view_point->x -= 0.1;
	}
	else if (key == DOWN)
	{
		this->renderer->camera->pos->y += 0.1;
		this->renderer->camera->view_point->y -= 0.1;
	}
	else
	{
		delegate_move_camera_part2(this, key);
		return ;
	}
	renderer_set_view(this->renderer);
	renderer_multiply_matrices(this->renderer);
}

void	delegate_move_camera_part2(t_delegate *this, t_key_codes key)
{
	if (key == UP)
	{
		this->renderer->camera->pos->y -= 0.1;
		this->renderer->camera->view_point->y += 0.1;
	}
	else if (key == NUM_1)
	{
		this->renderer->camera->pos->z += 0.1;
		this->renderer->camera->view_point->z -= 0.1;
	}
	else if (key == NUM_0)
	{
		this->renderer->camera->pos->z -= 0.1;
		this->renderer->camera->view_point->z += 0.1;
	}
	renderer_set_view(this->renderer);
	renderer_multiply_matrices(this->renderer);
}
