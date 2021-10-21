#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"

#include "ft_printf.h"
#include "vertex.h"
#include "generate.h"
#include "utils/arraylist.h"

t_model3D	*generate_parse_arguments(t_cli *cli_obj)
{
	t_arraylist	*vertices_raw;
	t_arraylist	*vertices;
	t_model3D	*model;

	vertices_raw = generate_read_file(cli_obj->file);
	vertices = generate_convert_vertices(vertices_raw);
	arraylist_delete(&vertices_raw, free);
	model = model3D_new(vertices);
	arraylist_delete(&vertices, generate_vertex3D_delete);
	return (model);
}

void	generate_vertex3D_delete(void *vertex)
{
	vertex3D_delete((t_vertex3D *) vertex);
}

t_arraylist	*generate_read_file(char *file_name)
{
	char		*line;
	int			fd;
	t_arraylist	*ret;
	t_arraylist	*tmp;

	ret = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd >= 0)
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			tmp = arraylist_new((void *) ft_split(line, ' '));
			if (tmp == NULL || tmp->content == NULL)
				perror("FdF");
				// TODO malloc protection!!!
			arraylist_append_unsafe(&ret, tmp);
			line = get_next_line(fd);
		}
	}
	return (ret);
}

t_arraylist	*generate_convert_vertices(t_arraylist *raw_vertices)
{
	t_arraylist	*ret;
	size_t		i;

	ret = NULL;
	while (raw_vertices != NULL)
	{
		i = 0;
		while (((void **) raw_vertices->content)[i] != NULL)
		{
		// TODO malloc protection!!!
			arraylist_append_unsafe(
				&ret,
				arraylist_new(
					vertex3D_new(
						i,
						raw_vertices->index,
						ft_atoi(((char **) raw_vertices->content)[i]))));
			i++;
		}
		raw_vertices = raw_vertices->next;
	}
	return (ret);
}
