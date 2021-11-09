#include "utils/math/vector.h"
#include "renderer.h"

void	renderer_generate_vectors(t_renderer_camera *cam)
{
	cam->depth = renderer_generate_depth(cam);
	cam->width = renderer_generate_right(cam);
	cam->height = renderer_generate_up(cam);
}

#include <stdio.h>
t_vector	*renderer_generate_depth(t_renderer_camera *cam)
{
	t_vector	pos;
	t_vector	v_p;
	t_vector	tmp;
	double		norm;

	vector_create(&pos, cam->pos->x, cam->pos->y, cam->pos->z);
	vector_create(&v_p, cam->view_point->x, cam->view_point->y,
		cam->view_point->z);
	vector_substract(&tmp, &v_p, &pos);
	printf("%f\n", vector_length(&tmp));
	norm = 1 / vector_length(&tmp);
	return (vector_new_multiply_digit(&tmp, norm));
}

t_vector	*renderer_generate_right(t_renderer_camera *cam)
{
	return (vector_new_multiply(cam->depth, cam->height));
}

t_vector	*renderer_generate_up(t_renderer_camera *cam)
{
	t_vector	w_u;
	t_vector	tmp;
	t_vector	tmp2;
	float		norm;

	vector_create(&w_u, 0, 1, 0);
	vector_multiply_digit(&tmp, cam->depth, vector_scalar_product(cam->depth, &w_u));
	vector_substract(&tmp2, &w_u, &tmp);
	norm = 1 / vector_length(&tmp2);
	return (vector_new_multiply_digit(&tmp2, norm));
}
