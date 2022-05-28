#include "./includes/so_long.h"

int main(void)
{
	//t_game mlx;
	void *mlx_new;
	void *mlx_win;

	mlx_new = mlx_init();
	mlx_win = mlx_new_window(mlx_new, 700, 400, "SO_LONG");
	mlx_pixel_put(mlx_new, mlx_win, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx_win, key_hook, (void *)0);
	mlx_hook(mlx_win, 33, 1L << 5, exit_hook, (void *)0); 
	//ウィンドウをXマーククリックで閉じる
	mlx_loop(mlx_new);
}
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_, &vars);
	mlx_loop(vars.mlx);
}
*/
//実行できたコマンド gcc main.c -Lmlx_linux  -lmlx -lm -lXext -lbsd -lX11
