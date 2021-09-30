#include <stdlib.h>

#include "arraylist.h"

void	**arraylist_to_array(t_arraylist *this)
{
	void	**array;
	size_t	counter;

	array = malloc(arraylist_size(this) * sizeof(void *));
	counter = 0;
	while (this != NULL)
	{
		array[counter] = this->content;
		counter++;
		this = this->next;
	}
	return (array);
}

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

void	**arraylist_to_array_unsafe(t_arraylist *this)
{
	void	**array;

	array = malloc(arraylist_size_unsafe(this) * sizeof(void *));
	while (this != NULL)
	{
		array[this->index] = this->content;
		this = this->next;
	}
	return (array);
}
