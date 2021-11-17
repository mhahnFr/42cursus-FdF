#include "renderer.h"

void	renderer_clear_buffer(t_renderer *this)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (this == NULL || this->buffer == NULL)
		return ;
	i = 0;
	while (i < this->buffer->width)
	{
		j = 0;
		while (j < this->buffer->height)
		{
			dst = this->buffer->raw + i * (this->buffer->depth / 8)
				+ j * this->buffer->line_size;
			*(unsigned int *) dst = this->buffer->background_color;
			j++;
		}
		i++;
	}
}
