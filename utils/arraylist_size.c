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
	while (this->next != NULL)
		this = this->next;
	return (this->index + 1);
}
