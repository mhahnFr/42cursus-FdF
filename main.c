#include "mlx.h"

#include "main.h"
#include "delegate/app_delegate.h"
#include "view/init.h"
#include "model/generate.h"
#include "model/model.h"
#include "CLI/cli.h"


#include "utils/math/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
void test() {
	float **a = malloc(4*sizeof(float*));
	a[0] = malloc(4*sizeof(float));
	a[1] = malloc(4*sizeof(float));
	a[2] = malloc(4*sizeof(float));
	a[3] = malloc(4*sizeof(float));
	
	float **b = malloc(4*sizeof(float*));
	b[0] = malloc(4*sizeof(float));
	b[1] = malloc(4*sizeof(float));
	b[2] = malloc(4*sizeof(float));
	b[3] = malloc(4*sizeof(float));

	int q = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			a[i][j] = q++;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			b[i][j] = q++;
	t_matrix *am = matrix_new(a, 3, 4);
	t_matrix *bm = matrix_new(b, 4, 1);
	t_matrix *cm = matrix_new_multiply(am, bm);
	printf("%p\n", cm);
	printf("%u %u\n", cm->rows, cm->columns);
	//matrix_multiply_m4x4_m4x4(&c, a, b);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++)
			printf("  %f  ", cm->values[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			printf("  %f  ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++)
			printf("  %f  ", b[i][j]);
		printf("\n");
	}

	/*t_vec4 d = {1, 2, 3, 4};
	t_vec4 e = {};
	matrix_multiply_m4x4_v4(&e, a, d);
	for (int i = 0; i < 4; i++)
		printf("  %f  ", e[i]);
	printf("\n");*/
}

int	main(int argc, char **argv)
{
	void		*mlx;
	t_model3D	*model;
	t_cli		*cli_obj;

	test();
	cli_obj = cli(argc, argv);
	model = generate_parse_arguments(cli_obj);
	mlx = init_mlx();
	return (onApplicationFinishedLaunching(model, mlx, cli_obj));
}
