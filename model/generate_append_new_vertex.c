#include "utils/arraylist.h"
#include "generate.h"

bool	generate_append_new_vertex(
			t_arraylist *raw_vertices,
			size_t i,
			t_arraylist **i_list)
{
	t_arraylist	*tmp;

	tmp = arraylist_new(generate_vertex(i, raw_vertices->index,
				((char **) raw_vertices->content)[i]));
	if (tmp == NULL || tmp->content == NULL)
		return (false);
	arraylist_append_unsafe(i_list, tmp);
	return (true);
}
