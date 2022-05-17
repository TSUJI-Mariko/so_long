#include "./mlx_linux/mlx.h"
#include "./mlx_linux/mlx_int.h"

int main(void)
{
	void *mlx;
//	void *mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}

//実行できたコマンド gcc main.c -Lmlx_linux  -lmlx -lm -lXext -lbsd -lX11
