#include <arraylist.h>

unsigned int	arraylist_size(t_arraylist *this)
{
	unsigned int	count;

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
	while (this != NULL)
		this = this->next;
	return (this->index + 1);
}
