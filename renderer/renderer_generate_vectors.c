#include "utils/math/vector.h"
#include "renderer.h"

void	renderer_generate_vectors(t_renderer_camera *cam)
{
	cam->depth = renderer_generate_depth(cam);
	cam->width = renderer_generate_right(cam);
	cam->height = renderer_generate_up(cam);
}

t_vector	*renderer_generate_depth(t_renderer_camera *cam)
{
	t_vector	pos;
	t_vector	v_p;
	t_vector	tmp;

	vector_create(&pos, cam->pos->x, cam->pos->y, cam->pos->z);
	vector_create(&v_p, cam->view_point->x, cam->view_point->y,
		cam->view_point->z);
	vector_substract(&tmp, &v_p, &pos);
	return (vector_new_division(&tmp, vector_length(&tmp)));
}

t_vector	*renderer_generate_right(t_renderer_camera *cam)
{
	t_vector	tmp;
	t_vector	w_u;

	vector_create(&w_u, 0, 1, 0);
	vector_multiply(&tmp, cam->depth, &w_u);
	return (vector_new_division(&tmp, vector_length(&tmp)));
}

t_vector	*renderer_generate_up(t_renderer_camera *cam)
{
	t_vector	tmp;
	t_vector	tmp2;
	t_vector	u_w;

	vector_create(&u_w, 0, 1, 0);
	vector_multiply(&tmp, cam->depth, &u_w);
	vector_multiply(&tmp2, &tmp, cam->depth);
	vector_substract(&tmp, &u_w, &tmp2);
	return (vector_new_division(&tmp, vector_length(&tmp)));
}
