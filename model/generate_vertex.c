#include <stdio.h>

#include "libft.h"

#include "vertex.h"
#include "generate.h"
#include "utils/hex_str_to_unsigned_int.h"

t_vertex3D	*generate_vertex(size_t x, size_t y, char *raw_z)
{
	t_vertex3D		*ret;
	char			*c;
	unsigned int	raw_color;

	if (raw_z == NULL)
		return (NULL);
	ret = vertex3D_new(x, y, ft_atoi(raw_z));
	if (ret == NULL)
		return (NULL);
	c = ft_strchr(raw_z, ',');
	if (c != NULL)
	{
		raw_color = generate_color(c + 1);
		ret->r = (raw_color >> 16) & 0xFF;
		ret->g = (raw_color >> 8) & 0xFF;
		ret->b = (raw_color >> 0) & 0xFF;
	}
	return (ret);
}

unsigned int	generate_color(char *string)
{
	if (string == NULL)
		return (0);
	return (hexstr_to_uint(string + 2));
}
