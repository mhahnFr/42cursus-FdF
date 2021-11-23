#include "ft_printf.h"

#include "app_delegate.h"
#include "renderer/renderer.h"
#include "view/event/key_codes.h"

void	delegate_main_window_key_touched_proj(
			t_delegate *this,
			t_key_codes key)
{
	if (key == P)
	{
		renderer_set_perspective_projection(this->renderer);
		renderer_multiply_matrices(this->renderer);
	}
	else if (key == O)
	{
		renderer_set_orthogonal_projection(this->renderer);
		renderer_multiply_matrices(this->renderer);
	}
	else
		delegate_main_window_key_touched_arrows(this, key);
}

void	delegate_main_window_key_touched_zoom(
			t_delegate *this,
			t_key_codes key)
{
	if (key == NUM_PLUS)
		ft_printf("TODO: Zoom in\n");
	else if (key == NUM_MINUS)
		ft_printf("TODO: Zoom out\n");
	else
		delegate_main_window_key_touched_toggle(this, key);
}

void	delegate_main_window_key_touched_toggle(
			t_delegate *this,
			t_key_codes key)
{
	if (key == SPACE)
		this->move_camera = !this->move_camera;
}
