#include "arraylist.h"

size_t	arraylist_size(t_arraylist *this)
{
	size_t	count;

	count = 0;
	while (this != NULL)
	{
		count += 1;
		this = this->next;
	}
	return (count);
}

size_t	arraylist_size_unsafe(t_arraylist *this)
{
	if (this == NULL)
		return (0);
	while (this->next != NULL)
		this = this->next;
	return (this->index + 1);
}
