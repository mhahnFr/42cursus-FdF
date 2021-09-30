#include <stdlib.h>

#include "arraylist.h"

void	arraylist_remove_at_element(
			t_arraylist **this,
			t_arraylist **element,
			void (*remover)(void*))
{
	t_arraylist	*tmp;

	if (this == NULL || *this == NULL || element == NULL)
		return ;
	tmp = *this;
	while (tmp != NULL)
	{
		if (tmp == *element)
		{
			if (tmp->next != NULL)
				tmp->next->previous = tmp->previous;
			if (tmp->previous != NULL)
				tmp->previous->next = tmp->next;
			if (tmp == *this)
				*this = tmp->next;
			arraylist_delete(&tmp, remover);
			break ;
		}
		tmp = tmp->next;
	}
}

void	arraylist_remove_at_index(
			t_arraylist **this,
			unsigned int index,
			void (*remover)(void *))
{
	t_arraylist	*tmp;

	if (this == NULL)
		return ;
	tmp = *this;
	while (tmp != NULL)
	{
		if (tmp->index == index)
		{
			if (tmp->next != NULL)
				tmp->next->previous = tmp->previous;
			if (tmp->previous != NULL)
				tmp->previous->next = tmp->next;
			if (tmp == *this)
				*this = tmp->next;
			arraylist_delete(&tmp, remover);
			break ;
		}
		tmp = tmp->next;
	}
}

void	arraylist_delete(t_arraylist **this, void (*remover)(void *))
{
	if (this != NULL && *this != NULL)
	{
		if (remover != NULL)
			remover((*this)->content);
		free(*this);
	}
	*this = NULL;
}
