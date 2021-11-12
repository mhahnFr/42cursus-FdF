#include <stdio.h>

#include "generate.h"

inline t_arraylist	*generate_error_clear_double(
						t_arraylist **list,
						t_arraylist_remover r,
						t_arraylist **second,
						t_arraylist_remover r_second)
{
	arraylist_clear(list, r);
	return (generate_error_clear(second, r_second));
}

inline t_arraylist	*generate_error_clear(
						t_arraylist **list,
						t_arraylist_remover r)
{
	perror("FdF");
	arraylist_clear(list, r);
	return (NULL);
}
