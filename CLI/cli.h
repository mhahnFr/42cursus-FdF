#ifndef CLI_H
# define CLI_H

# include <stdbool.h>

/*
 * The representation of the arguments passed via the command line. Consists of
 * the name of the executable, the file that should be opened, and optionally
 * the width and height of the window.
 */
typedef struct s_cli
{
	char	*name;
	char	*file;
	int		width;
	int		height;
	bool	size_set;
}	t_cli;

/*
 * Prints a small help screen and exits the application. Takes as parameter the
 * name of the executable in order to display it properly to the user.
 */
void	cli_print_help_exit(const char *app_name);

/*
 * Parses the given arguments.
 */
t_cli	*cli(int argc, char **argv);

/*
 * Creates a new CLI object containing the infos that were passed on the
 * command line. Returns the newly allocated object, or null if the allocation
 * failed.
 */
t_cli	*cli_new(int argc, char **argv);

/*
 * Initializes the content of the given CLI object using the given parameters.
 * Does nothing if no object is given.
 */
void	cli_create(t_cli *this, int argc, char **argv);

/*
 * Calls the perror function with the program name and the file name as
 * parameters. Takes as parameter an CLI object. Does nothing if no object is
 * given.
 */
void	cli_file_error(t_cli *this);

/*
 * Destroys the content of the given CLI object. Does nothing if no object is
 * given.
 */
void	cli_destroy(t_cli *this);

/*
 * Deletes the given CLI object. Does nothing if no object is given.
 */
void	cli_delete(t_cli *this);

#endif
