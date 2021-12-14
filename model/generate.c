#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

#include "model.h"
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
	arraylist_clear(
		&vertices_raw,
		(t_arraylist_remover) generate_del_chr_ar);
	model = model3D_new(
			generate_convert_and_count_contents(vertices),
			arraylist_size_unsafe(vertices),
			(t_vertex3D ***) arraylist_to_array_transfer_unsafe(&vertices));
	return (model);
}

size_t	*generate_convert_and_count_contents(t_arraylist *list)
{
	t_arraylist	*tmp;
	size_t		*ret;
	size_t		count;

	if (list == NULL)
		return (NULL);
	ret = malloc(sizeof(size_t) * arraylist_size_unsafe(list));
	if (ret == NULL)
		return (NULL);
	count = 0;
	while (list != NULL)
	{
		tmp = (t_arraylist *) list->content;
		ret[count] = arraylist_size_unsafe(tmp);
		list->content = arraylist_to_array_transfer_unsafe(&tmp);
		list = list->next;
		count++;
	}
	return (ret);
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
	if (fd < 0)
		return (NULL);
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
	close(fd);
	return (r);
}

t_arraylist	*generate_convert_vertices(t_arraylist *raw_vertices)
{
	t_arraylist	*ret;
	t_arraylist	*i_list;
	t_arraylist	*tmp;
	size_t		i;

	ret = NULL;
	while (raw_vertices != NULL)
	{
		i = 0;
		i_list = NULL;
		while (((void **) raw_vertices->content)[i] != NULL)
		{
			if (!generate_append_new_vertex(raw_vertices, i, &i_list))
				return (generate_error_clear_double(&i_list,
						(t_arraylist_remover) vertex3D_delete, &ret, NULL));
			i++;
		}
		tmp = arraylist_new(i_list);
		if (tmp == NULL)
			return (generate_error_clear_double(&i_list,
					(t_arraylist_remover) vertex3D_delete, &ret, NULL));
		arraylist_append_unsafe(&ret, tmp);
		raw_vertices = raw_vertices->next;
	}
	return (ret);
}
