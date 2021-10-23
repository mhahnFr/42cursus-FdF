#ifndef GENERATE_H
# define GENERATE_H

# include "model.h"
# include "utils/arraylist.h"
# include "CLI/cli.h"

/*
 * Reads the arguments that were given to this application. Creates a model
 * based on this data. Takes the arguments and their count as parameters.
 * Returns a pointer to the model that has been created.
 */
t_model3D	*generate_parse_arguments(t_cli *cli_obj);

/*
 * Reads the file and splits it by its spaces. Returns an arraylist object
 * consisting of all lines read from the given file, splitted by the space.
 */
t_arraylist	*generate_read_file(char *file_name);

/*
 * Deletes the given char array. The last element of the given array has to be
 * a null pointer, as it serves as indicator of the end of the array. Does
 * nothing if no rray is given.
 */
void		generate_delete_char_array(char **array);

/*
 * Converts the given arraylist containing the raw vertex data read from the
 * file to a newly allocated arraylist consisting of vertex objects. Returns
 * the new arraylist or null, when either the allocation failed or no arraylist
 * is given.
 *
 * Hint: probably use an array, as that won't change!
 */
t_arraylist	*generate_convert_vertices(t_arraylist *raw_vertices);

#endif
