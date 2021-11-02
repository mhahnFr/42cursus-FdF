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
	size_t		count;

	vertices_raw = generate_read_file(cli_obj->file);
	vertices = generate_convert_vertices(vertices_raw);
	arraylist_clear(
		&vertices_raw,
		(t_arraylist_remover) generate_del_chr_ar);
	count = arraylist_size(vertices);
	model = model3D_new(
			(t_vertex3D **) arraylist_to_array_transfer(&vertices),
			count);
	return (model);
}

void	generate_del_chr_ar(char **array)
{
	size_t	counter;

	if (array == NULL)
		return ;
	counter = 0;
	while (array[counter] != NULL)
		free(array[counter++]);
	free(array);
}

t_arraylist	*generate_read_file(char *file_name)
{
	char		*line;
	int			fd;
	t_arraylist	*r;
	t_arraylist	*tmp;

	r = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd >= 0)
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			tmp = arraylist_new((void *) ft_split(line, ' '));
			if (tmp == NULL || tmp->content == NULL)
			{
				perror("FdF");
				arraylist_clear(&r, (t_arraylist_remover) generate_del_chr_ar);
				return (NULL);
			}
			arraylist_append_unsafe(&r, tmp);
			free(line);
			line = get_next_line(fd);
		}
	}
	return (r);
}

t_arraylist	*generate_convert_vertices(t_arraylist *raw_vertices)
{
	t_arraylist	*ret;
	t_arraylist	*tmp;
	size_t		i;

	ret = NULL;
	while (raw_vertices != NULL)
	{
		i = 0;
		while (((void **) raw_vertices->content)[i] != NULL)
		{
			tmp = arraylist_new(
					vertex3D_new(i, raw_vertices->index,
						ft_atoi(((char **) raw_vertices->content)[i])));
			if (tmp == NULL || tmp->content == NULL)
			{
				perror("FdF");
				arraylist_clear(&ret, (t_arraylist_remover) vertex3D_delete);
				return (NULL);
			}
			arraylist_append_unsafe(&ret, tmp);
			i++;
		}
		raw_vertices = raw_vertices->next;
	}
	return (ret);
}
