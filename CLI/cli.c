#include <stdlib.h>

#include "libft.h"
#include "cli.h"

void	print_help_exit(const char *app_name)
{
	ft_putstr_fd("Usage: ", 1);
	ft_putstr_fd((char *) app_name, 1);
	ft_putstr_fd(" <file> \n", 1);
	exit(0);
}

void	cli(int argc, char **argv)
{
	if (argc == 1)
		print_help_exit(argv[0]);
}
