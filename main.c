#include "mlx.h"

#include "main.h"
#include "delegate/app_delegate.h"
#include "view/init.h"
#include "model/generate.h"
#include "model/model.h"
#include "CLI/cli.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	t_model3D	*model;
	t_cli		*cli_obj;

	cli_obj = cli(argc, argv);
	model = generate_parse_arguments(cli_obj);
	mlx = init_mlx();
	return (onApplicationFinishedLaunching(model, mlx, cli_obj));
}
