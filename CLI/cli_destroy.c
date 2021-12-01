#include <stdlib.h>

#include "cli.h"

void	cli_destroy(t_cli __attribute__((unused)) *this)
{
}

void	cli_delete(t_cli *this)
{
	cli_destroy(this);
	if (this != NULL)
		free(this);
}
