#ifndef GENERATE_H
# define GENERATE_H

# include <stdbool.h>

# include "utils/arraylist.h"
# include "CLI/cli.h"

typedef struct s_model3D	t_model3D;

typedef struct s_vertex3D	t_vertex3D;

/*
 * Reads the arguments that were given to this application. Creates a model
 * based on this data. Takes the arguments and their count as parameters.
 * Returns a pointer to the model that has been created.
 */
t_model3D		*generate_parse_arguments(t_cli *cli_obj);

/*
 * Reads the file and splits it by its spaces. Returns an arraylist object
 * consisting of all lines read from the given file, splitted by the space.
 */
t_arraylist		*generate_read_file(char *file_name);

/*
 * Deletes the given char array. The last element of the given array has to be
 * a null pointer, as it serves as indicator of the end of the array. Does
 * nothing if no rray is given.
 */
void			generate_del_chr_ar(char **array);

/*
 * Converts the given arraylist containing the raw vertex data read from the
 * file to a newly allocated arraylist consisting of vertex objects. Returns
 * the new arraylist or null, when either the allocation failed or no arraylist
 * is given.
 *
 * Hint: probably use an array, as that won't change!
 */
t_arraylist		*generate_convert_vertices(t_arraylist *raw_vertices);

bool			generate_append_new_vertex(
					t_arraylist *raw_vertices,
					size_t i,
					t_arraylist **i_list);

/*
 * Converts all arraylists inside of the given list to arrays and stores them
 * in that list. Stores the count of each list inside of a new array, which is
 * returned. Uses the unsafe arraylist functions. Returns either the newly
 * allocated array or null if either the allocation failed or no list is given.
 */
size_t			*generate_convert_and_count_contents(t_arraylist *list);

/*
 * Allocates a new vertex with the given data. Returns either the newly
 * allocated vertex or null if either the allocation failed or the string is
 * missing.
 */
t_vertex3D		*generate_vertex(size_t x, size_t y, char *raw_z);

/*
 * Converts the given string to an unsigned int. The string has to contain a
 * hexadecimal number, with 0x as the first characters. Return zero in case of
 * error.
 */
unsigned int	generate_color(char *string);

/*
 * Clears the two given lists with the given remove functions. Displays an
 * error message on the the standard error stream.
 */
t_arraylist		*generate_error_clear_double(
					t_arraylist **list,
					t_arraylist_remover r,
					t_arraylist **second,
					t_arraylist_remover r_second);

/*
 * Clears the given list using the given remove function. Displays an error
 * message on the standard error stream.
 */
t_arraylist		*generate_error_clear(
					t_arraylist **list,
					t_arraylist_remover r);

#endif
