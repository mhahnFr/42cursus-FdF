#include <stdlib.h>

#include "arraylist.h"

void	arraylist_remove_at_element(
			t_arraylist **this,
			t_arraylist **element,
			t_arraylist_remover remover)
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
			size_t index,
			t_arraylist_remover remover)
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

void	arraylist_delete(t_arraylist **this, t_arraylist_remover remover)
{
	if (this != NULL && *this != NULL)
	{
		if (remover != NULL)
			remover((*this)->content);
		free(*this);
	}
	*this = NULL;
}

void	arraylist_clear(t_arraylist **this, t_arraylist_remover remover)
{
	t_arraylist	*tmp;
	t_arraylist	*n;

	if (this == NULL)
		return ;
	tmp = *this;
	while (tmp != NULL)
	{
		n = tmp->next;
		arraylist_delete(&tmp, remover);
		tmp = n;
	}
	*this = NULL;
}
