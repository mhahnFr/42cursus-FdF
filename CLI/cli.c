#include <stdlib.h>

#include "cli.h"

#include "ft_printf.h"
#include "libft.h"

void	print_help_exit(const char *app_name)
{
	ft_printf("Usage: %s <file> [width height]\n", app_name);
	exit(0);
}

t_cli	*cli(int argc, char **argv)
{
	t_cli	*ret;

	if (argc == 1)
		print_help_exit(argv[0]);
	else if (argc == 3)
		print_help_exit(argv[0]);
	else if (argc > 4)
		print_help_exit(argv[0]);
	ret = cli_new(argc, argv);
	return (ret);
}

t_cli	*cli_new(int argc, char **argv)
{
	t_cli	*ret;

	ret = malloc(sizeof(struct s_cli));
	if (ret != NULL)
	{
		ret->name = argv[0];
		ret->file = argv[1];
		ret->size_set = false;
		if (argc == 4)
		{
			ret->width = ft_atoi(argv[2]);
			ret->height = ft_atoi(argv[3]);
			ret->size_set = true;
		}
	}
	return (ret);
}

void	cli_delete(t_cli *this)
{
	if (this != NULL)
		free(this);
}
