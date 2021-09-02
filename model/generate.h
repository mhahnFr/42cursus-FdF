#ifndef GENERATE_H
# define GENERATE_H

/*
 * Reads the arguments that were given to this application. Creates a model
 * based on this data. Takes the arguments and their count as parameters.
 * Returns a pointer to the model that has been created.
 */
void	*parse_arguments(int argc, char **argv);

#endif
