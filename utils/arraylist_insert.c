#include "arraylist.h"

bool	arraylist_insert_at(
			t_arraylist **this,
			t_arraylist *element,
			size_t index)
{
	t_arraylist	*tmp;

	if (this == NULL || *this == NULL || element == NULL)
		return (false);
	tmp = arraylist_get_element(*this, index);
	if (tmp == NULL)
	{
		arraylist_append(this, element);
		return (false);
	}
	if (tmp->previous != NULL)
		tmp->previous->next = element;
	element->previous = tmp->previous;
	element->next = tmp;
	tmp->previous = element;
	// TODO index repair
	return (true);
}

bool	arraylist_insert_at_unsafe(
				t_arraylist **this,
				t_arraylist *element,
				size_t index)
{
	t_arraylist	*tmp;

	if (this == NULL || *this == NULL || element == NULL)
		return (false);
	tmp = arraylist_get_element_unsafe(*this, index);
	if (tmp == NULL)
	{
		arraylist_append_unsafe(this, element);
		return (false);
	}
	if (tmp->previous != NULL)
		tmp->previous->next = element;
	element->previous = tmp->previous;
	element->next = tmp;
	tmp->previous = element;
	// TODO index repair
	return (true);
}

bool	arraylist_insert_before(
			t_arraylist **this,
			t_arraylist *element,
			t_arraylist *new)
{
	t_arraylist	*tmp;

	if (this == NULL || element == NULL || new == NULL)
		return (false);
	tmp = *this;
	while (tmp != NULL)
	{
		if (tmp == element)
		{
			new->previous = element->previous;
			if (element->previous != NULL)
				element->previous->next = new;
			element->previous = new;
			new->next = element;
			// TODO index repair
			return (true);
		}
		tmp = tmp->next;
	}
	arraylist_append(this, new);
	return (false);
}

bool	arraylist_insert_after(
			t_arraylist **this,
			t_arraylist *element,
			t_arraylist *new)
{
	t_arraylist	*tmp;

	if (this == NULL || element == NULL || new == NULL)
		return (false);
	tmp = *this;
	while (tmp != NULL)
	{
		if (tmp == element)
		{
			new->previous = tmp;
			new->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->previous = new;
			tmp->next = new;
			// TODO index repair
			return (true);
		}
	}
	arraylist_append(this, new);
	return (false);
}
