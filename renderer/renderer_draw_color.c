#include <math.h>

#include "utils/point.h"
#include "renderer.h"

void	renderer_draw_coloured_point(
			t_point *current,
			t_point *start,
			t_point *end,
			t_renderer_image *buf)
{
	float	id;
	float	fraction;

	id = sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
	fraction
		= sqrt(pow(current->x - start->x, 2)
			+ pow(current->y - start->y, 2)) / id;
	current->r = start->r + ((end->r - start->r) * fraction);
	current->g = start->g + ((end->g - start->g) * fraction);
	current->b = start->b + ((end->b - start->b) * fraction);
	renderer_draw_point(current, buf);
}
