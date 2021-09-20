#include "mlx.h"

#include "delegate/app_delegate.h"
#include "view/init.h"
#include "model/generate.h"
#include "CLI/cli.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*model;

	cli(argc, argv);
	model = parse_arguments(argc, argv);
	mlx = init_mlx();
	return (onApplicationFinishedLaunching(model, mlx));
}
