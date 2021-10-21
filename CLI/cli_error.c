#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

#include "cli.h"

void	cli_file_error(t_cli *this)
{
	char	*err_str;

	if (this != NULL && this->file != NULL)
	{
		err_str = ft_strjoin("FdF: ", this->file);
		if (err_str == NULL)
		{
			perror("FdF");
			return ;
		}
		perror(err_str);
		free(err_str);
	}
}
