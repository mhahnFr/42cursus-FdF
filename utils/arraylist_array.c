#include <stdlib.h>

#include "arraylist.h"

void	**arraylist_to_array(t_arraylist *this, void *(*dup)(void *))
{
	void	**array;
	size_t	counter;

	if (dup == NULL)
		return (NULL);
	array = malloc(arraylist_size(this) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	counter = 0;
	while (this != NULL)
	{
		array[counter] = dup(this->content);
		counter++;
		this = this->next;
	}
	return (array);
}

void	**arraylist_to_array_unsafe(t_arraylist *this, void *(*dup)(void *))
{
	void	**array;

	if (dup == NULL)
		return (NULL);
	array = malloc(arraylist_size_unsafe(this) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	while (this != NULL)
	{
		array[this->index] = this->content;
		this = this->next;
	}
	return (array);
}

void	**arraylist_to_array_transfer(t_arraylist **this)
{
	void	**array;

	array = arraylist_to_array_transfer_unsafe(*this);
	if (array != NULL)
		arraylist_clear(this, NULL);
	return (array);
}

void	**arraylist_to_array_transfer_core(t_arraylist *this)
{
	void	**array;
	size_t	counter;

	if (this == NULL)
		return (NULL);
	array = malloc(arraylist_size(this) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	counter = 0;
	while (this != NULL)
	{
		array[counter] = this->content;
		counter++;
		this = this->next;
	}
	return (array);
}
