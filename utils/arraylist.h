#ifndef ARRAYLIST_H
# define ARRAYLIST_H

# include <stddef.h>

/*
 * Represents an element of a linked list, which consists of an array of any
 * type, and a pointer to the next element. The index is automatically
 * overwritten by the appending method.
 */
typedef struct s_arraylist {
	void				*content;
	unsigned int		index;
	struct s_arraylist	*previous;
	struct s_arraylist	*next;
}	t_arraylist;

/*
 * Returns a newly allocated arraylist.
 */
t_arraylist		*arraylist_new(void *content);

/*
 * Deletes the element at the given index out of the list and deletes that
 * element afterwards. The content of that element will be deleted by the
 * optionally given delete function.
 */
void			arraylist_remove_at_index(
					t_arraylist **this,
					unsigned int index,
					void (*remover)(void *));

/*
 * Deletes the given element out of the list, deletes the element afterwards.
 * The pointer to the given element will be set to null. The content of that
 * element will be deleted with the given delete function. This function is
 * optional.
 */
void			arraylist_remove_at_element(
					t_arraylist **this,
					t_arraylist **element,
					void (*remover)(void *));

/*
 * Adds the given element to the given arraylist. If the pointer to the
 * beginning of the list is null, the appendix is the new beginning. If the
 * pointer to the beginning itself is null, this function does nothing. The
 * index of the appended element is also set.
 */
void			arraylist_append(t_arraylist **this, t_arraylist *appendix);

/*
 * Adds the given element to the given arraylist. If the pointer to the
 * beginning of the list is null, the appendix is the new beginning. If the
 * pointer to the beginning itself is null, this function does nothing. The
 * index of the appended element is also set, using the index of the previous
 * element, if there is one. Thereby, as this unsafe version is using the
 * changable index of each element, the index of the appended element might be
 * wrong in case the index of the last element has been manipulated. It does
 * not crash because of this.
 */
void			arraylist_append_unsafe(t_arraylist **this, t_arraylist *appendix);

/*
 * Converts the given arraylist to a simple array. Note that any changes made
 * to either object are not tracked by the other one. If an empty arraylist is
 * given, an empty array is returned. Returns either the newly allocated array
 * or null if either the allocation failed or no arraylist is given.
 */
void			**arraylist_to_array(t_arraylist *this);

/*
 * Converts the given arraylist to a simple array. Please note that any changes
 * made to either object are not tracked by the other one. If an empty
 * arraylist is given, an empty array is returned. Returns either the newly
 * alloacted array or null if either the allocation failed or no arraylist is
 * given. As this unsafe version is using the changable index of each element,
 * this method might crash in case the indices of the elements in the given
 * arraylist are manipulated.
 */
void			**arraylist_to_array_unsafe(t_arraylist *this);

/*
 * Deletes the given part of the arraylist. The function is an optional
 * function to delete the content of an element, if desired.
 */
void			arraylist_delete(t_arraylist **this, void (*remover)(void *));

/*
 * Returns the count of elements in the given arraylist. If no arraylist is
 * given, zero is returned.
 */
unsigned int	arraylist_size(t_arraylist *this);

/*
 * Returns the count of elements in the given arraylist. If no arraylist is
 * given, zero is returned. As this unsafe version is using the changable index
 * of each element, this method might crash in case the indices of the elements
 * in the given arraylist are manipulated.
 */
size_t			arraylist_size_unsafe(t_arraylist *this);

#endif
