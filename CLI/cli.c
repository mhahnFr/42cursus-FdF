#include <stdlib.h>

#include "cli.h"
#include "ft_printf.h"

void	print_help_exit(const char *app_name)
{
	ft_printf("Usage: %s <file> \n", app_name);
	exit(0);
}

void	cli(int argc, char **argv)
{
	if (argc == 1)
		print_help_exit(argv[0]);
	else if (argc > 2)
		print_help_exit(argv[0]);
}
