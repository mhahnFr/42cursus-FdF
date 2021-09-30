#include <stdlib.h>

#include "arraylist.h"

t_arraylist	*arraylist_new(void *content)
{
	t_arraylist	*ret;

	ret = malloc(sizeof(struct s_arraylist));
	if (ret != NULL)
	{
		ret->content = content;
		ret->previous = NULL;
		ret->next = NULL;
		ret->index = 0;
	}
	return (ret);
}

void	arraylist_append(t_arraylist **this, t_arraylist *appendix)
{
	t_arraylist	*tmp;
	size_t		counter;

	if (this == NULL)
		return ;
	else if (*this == NULL)
	{
		*this = appendix;
		(*this)->index = 0;
		return ;
	}
	tmp = *this;
	counter = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		counter += 1;
	}
	tmp->next = appendix;
	tmp->next->previous = tmp;
	appendix->index = counter;
}

void	arraylist_append_unsafe(t_arraylist **this, t_arraylist *appendix)
{
	t_arraylist	*tmp;

	if (this == NULL)
		return ;
	else if (*this == NULL)
	{
		*this = appendix;
		(*this)->index = 0;
		return ;
	}
	tmp = *this;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = appendix;
	tmp->next->previous = tmp;
	appendix->index = tmp->index + 1;
}
