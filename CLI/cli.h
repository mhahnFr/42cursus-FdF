#ifndef CLI_H
# define CLI_H

void	cli(int argc, char **argv);

/*
 * Prints a small help screen and exits the application. Takes as parameter the
 * name of the executable in order to display it properly to the user.
 */
void	print_help_exit(const char *app_name);

/*
 * Parses the given arguments.
 */
void	cli(int argc, char **argv);

#endif
