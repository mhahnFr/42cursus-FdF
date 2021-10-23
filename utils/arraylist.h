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
	size_t			index;
	struct s_arraylist	*previous;
	struct s_arraylist	*next;
}	t_arraylist;

typedef void *(*t_arraylist_dup)(void *);

typedef void (*t_arraylist_remover)(void *);

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
					size_t index,
					t_arraylist_remover remover);

/*
 * Deletes the given element out of the list, deletes the element afterwards.
 * The pointer to the given element will be set to null. The content of that
 * element will be deleted with the given delete function. This function is
 * optional.
 */
void			arraylist_remove_at_element(
					t_arraylist **this,
					t_arraylist **element,
					t_arraylist_remover remover);

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
void			arraylist_append_unsafe(
					t_arraylist **this,
					t_arraylist *appendix);

/*
 * Converts the given arraylist to a simple array. Note that any changes made
 * to either object are not tracked by the other one, as the array contains
 * duplicates of the contents of the arraylist using the given function. If an
 * empty arraylist is given, an empty array is returned. Returns either the
 * newly allocated array or null if either the allocation failed or no
 * arraylist or no duplicate function is given.
 */
void			**arraylist_to_array(
				t_arraylist *this,
				t_arraylist_dup dup);

/*
 * Converts the given arraylist to a simple array. Please note that any changes
 * made to either object are not tracked by the other one as the array contains
 * duplicates of the contents of the arraylist. If an empty arraylist is given,
 * an empty array is returned. Returns either the newly alloacted array or null
 * if either the allocation failed or no arraylist or no duplicate function is
 * given. As this unsafe version is using the changable index of each element,
 * this method might crash in case the indices of the elements in the given
 * arraylist are manipulated.
 */
void			**arraylist_to_array_unsafe(
				t_arraylist *this,
				t_arraylist_dup dup);

/*
 * Converts the given arraylist to a simple array. The contents of the given
 * arraylist are not duplicated, the given arraylist is deleted after the
 * transformation into an array without deleting the contents. If an empty
 * arraylist is given, an empty array is returned. Returns either the newly
 * allocated array or null if the allocation failed. If the array could not be
 * created, the given arraylist will not be deleted.
 */
void			**arraylist_to_array_transfer(t_arraylist **this);

/*
 * Converts the given arraylist to a simple array. The contents of the given
 * arraylist are not duplicated, but the given arraylist is also not deleted
 * after the transformation into an array. If an empty arraylist is given, an
 * empty array is returned. Returns either the newly allocated array or null if
 * the allocation failed.
 */
void			**arraylist_to_array_transfer_core(t_arraylist *this);

/*
 * Converts the given arraylist to a simple array. The contents of the given
 * arraylist are not duplicated, the given arraylist is deleted after the
 * transformation into an array without deleting the contents. If an empty
 * arraylist is given, an empty array is returned. Returns either the newly
 * allocated array or null if the allocation failed. If the array could not be
 * created, the given arraylist will not be deleted. As this method is using
 * other unsafe methods, it can crash or produce undefined behaviour and
 * results if the indices of the elements in the arraylist are manipulated.
 */
void			**arraylist_to_array_transfer_unsafe(
				t_arraylist **this);

/*
 * Converts the given arraylist to a simple array. The contents of the given
 * arraylist are not duplicated, but the given arraylist is also not deleted
 * after the transformation into an array. If an empty arraylist is given, an
 * empty array is returned. Returns either the newly allocated array or null if
 * the allocation failed. As this method is using other unsafe methods and
 * relies itself on the changable index of each element in the given arraylist,
 * it can crash or produce undefined behaviour and results if the indices of
 * the elements in the arraylist are manipulated.
 */
void			**arraylist_to_array_transfer_core_unsafe(
				t_arraylist *this);

/*
 * Deletes the given part of the arraylist. The function is an optional
 * function to delete the content of an element, if desired.
 */
void			arraylist_delete(
				t_arraylist **this,
				t_arraylist_remover remover);

/*
 * Returns the count of elements in the given arraylist. If no arraylist is
 * given, zero is returned.
 */
size_t			arraylist_size(t_arraylist *this);

/*
 * Returns the count of elements in the given arraylist. If no arraylist is
 * given, zero is returned. As this unsafe version is using the changable index
 * of each element, this method might crash in case the indices of the elements
 * in the given arraylist are manipulated.
 */
size_t			arraylist_size_unsafe(t_arraylist *this);

/*
 * Deletes the whole given list. Uses the optionally given delete function to
 * remove the contents of each element. If no list is given, this function does
 * nothing.
 */
void			arraylist_clear(
				t_arraylist **this,
				t_arraylist_remover remover);

#endif
