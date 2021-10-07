#include "mlx.h"

#include "main.h"
#include "delegate/app_delegate.h"
#include "view/init.h"
#include "model/generate.h"
#include "model/model.h"
#include "CLI/cli.h"

/*
#include "utils/math/matrix_new.h"
#include <stdio.h>
void test() {
	t_matrix4x4 a = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};
	t_matrix4x4 b = {
		{ 17, 18, 19, 20 },
		{ 21, 22, 23, 24 },
		{ 25, 26, 27, 28 },
		{ 29, 30, 31, 32 }
	};
	t_matrix4x4 c = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}  };
	matrix_multiply_m4x4_m4x4(&c, a, b);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("  %f  ", c[i][j]);
		printf("\n");
	}

	t_vec4 d = {1, 2, 3, 4};
	t_vec4 e = {};
	matrix_multiply_m4x4_v4(&e, a, d);
	for (int i = 0; i < 4; i++)
		printf("  %f  ", e[i]);
	printf("\n");
}*/

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
