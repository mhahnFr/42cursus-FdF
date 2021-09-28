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

	cli(argc, argv);
	model = parse_arguments(argc, argv);
	mlx = init_mlx();
	return (onApplicationFinishedLaunching(model, mlx));
}
