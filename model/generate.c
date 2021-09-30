#include <fcntl.h>
#include <stddef.h>

#include "libft.h"
#include "get_next_line.h"

#include "ft_printf.h"
#include "vertex.h"
#include "generate.h"
#include "utils/arraylist.h"

t_model3D	*generate_parse_arguments(int argc, char **argv)
{
	t_arraylist	*vertices_raw;
	t_arraylist	*vertices;
	t_model3D	*model;

	argc = -1;
	vertices_raw = generate_read_file(argv[1]);
	vertices = generate_convert_vertices(vertices_raw);
	model = model3D_new(vertices);
	return (model);
}

t_arraylist	*generate_read_file(char *file_name)
{
	char		*line;
	int			fd;
	t_arraylist	*ret;
	t_arraylist	*tmp;

	ret = NULL;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = arraylist_new((void *) ft_split(line, ' '));
		if (tmp == NULL || tmp->content == NULL)
			ft_printf("Error 1"); // throw new NullPointerException("malloc error!");
		arraylist_append_unsafe(&ret, tmp);
		line = get_next_line(fd);
	}
	return (ret);
}

t_arraylist	*generate_convert_vertices(t_arraylist *raw_vertices)
{
	t_arraylist	*ret;
	size_t		i;

	while (raw_vertices != NULL)
	{
		i = 0;
		while (((void **) raw_vertices->content)[i] != NULL)
		{
			arraylist_append_unsafe(&ret, arraylist_new(vertex3D_new(i, raw_vertices->index, ft_atoi(((char **) raw_vertices->content)[i]))));
			i++;
		}
		// TODO malloc protection!!!
		raw_vertices = raw_vertices->next;
	}
	return (ret);
}
