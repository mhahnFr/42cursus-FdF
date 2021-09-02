#include "mlx.h"

#include "./delegate/app_delegate.h"
#include "./view/init.h"
#include "./model/generate.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*model;

	model = parse_arguments(argc, argv);
	mlx = init_mlx();
	return (onApplicationFinishedLaunching(model, mlx));
}
