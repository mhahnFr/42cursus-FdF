#include "ft_printf.h"

#include "app_delegate.h"
#include "renderer/renderer.h"
#include "view/event/key_codes.h"

void	delegate_main_window_key_touched_proj(
			t_delegate *this,
			t_key_codes key)
{
	if (key == P)
		this->renderer->perspective = !this->renderer->perspective;
	else
	{
		delegate_main_window_key_touched_arrows(this, key);
		return ;
	}
	if (this->renderer->perspective)
		renderer_set_perspective_projection(this->renderer);
	else
		renderer_set_orthogonal_projection(this->renderer);
	renderer_multiply_matrices(this->renderer);
}

void	delegate_main_window_key_touched_zoom(
			t_delegate *this,
			t_key_codes key)
{
	if (key == NUM_PLUS)
		this->renderer->view_angle -= 1;
	else if (key == NUM_MINUS)
		this->renderer->view_angle += 1;
	else
	{
		delegate_main_window_key_touched_toggle(this, key);
		return ;
	}
	if (this->renderer->perspective)
		renderer_set_perspective_projection(this->renderer);
	else
		renderer_set_orthogonal_projection(this->renderer);
	renderer_multiply_matrices(this->renderer);
}

void	delegate_main_window_key_touched_toggle(
			t_delegate *this,
			t_key_codes key)
{
	if (key == SPACE)
		this->move_camera = !this->move_camera;
}
