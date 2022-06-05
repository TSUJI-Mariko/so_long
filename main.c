#include "./includes/so_long.h"

void	init_map2(t_game *game, char *map_all)
{
	if ( ft_strchr(map_all, 'E') == NULL
		|| ft_strchr(map_all, 'P') == NULL
		|| ft_strchr(map_all, 'C') == NULL )
		error_message("not E,P or C", map_all);
	if (game->line_char -1 == game->line_num)
		error_message("it's square map!", map_all);
	check_elements(map_all);
	game->map = ft_strdup(map_all);
	game->fd = close(game->fd);
	game->map_width = game->line_char * 32;
	game->map_height = (game->line_num - 1) * 32;
	free(map_all);
}

void	deal_line(int ret, char *line, t_game *game, char *map_all)
{

	while (ret > 0)
	{
		game->line_num++;
		game->line_end = ft_strlen(line) - 1;
		if (line[0] != '1' ||line[game->line_end] != '1')
		{
			ft_putstr_fd("wall is not surrounded by wall '1'", 2);
			free(map_all);
			exit(1);
		}
		ft_strcat(map_all, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if ((ret != 0) && ft_strlen(line) != game->line_char)
		{
			ft_putstr_fd("error", 2);
			free(map_all);
			exit(1);
		}
		
	}
	if (ret == 0)
	{
		game->line_num++;
		check_wall(line,map_all);
		ft_strcat(map_all, line);
		free(line);
		line = 0;
	}
	//free(map_all);
}

char init_map(t_game *game, char *map)
{
	char *line;
	int ret;
	char *map_all;
	
	game->move = 0;
	game->line_num = 0;
	map_all = malloc(sizeof(char *) * 10000);
	*map_all = 0;
	game->fd = open(map, O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("fd is '-1'", 2);
		free(map_all);
		exit(1);
	}
	line = 0;
	ret = get_next_line(game->fd, &line);
	check_wall(line, map_all);
	game->line_char = ft_strlen(line);
	deal_line(ret, line, game, map_all);
	init_map2(game, map_all);
	return (1);
}

void	load_image(t_game *game, t_img **image, char *filename)
{
	int height;
	int	width;
	*image = mlx_xpm_file_to_image(game->mlx.mlx, filename, &width, &height);
	(*image)->height = height;
	(*image)->width = width;
}

void	image_setting(t_game *game)
{
	load_image(game, &game->home, "./img/home.xpm");
	load_image(game, &game->back, "./img/ground_blue.xpm");
	load_image(game, &game->wall, "./img/tile.xpm");
	load_image(game, &game->collect, "./img/star.xpm");
	load_image(game, &game->person1, "./img/Mario1.xpm");
}

int	init_structure(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, game->map_width, game->map_height, "So_long"); 
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx, game->map_width, game->map_height);
	image_setting(game);
	return (1);
}

int main(int argc, char **argv)
{
	t_game game;
	//void *mlx_new;
	//void *mlx_win;

	if (argc != 2)
		return (0);
	init_map(&game, argv[1]);
	init_structure(&game);
	draw(&game);
	//right(&game);
//	mlx_pixel_put(game.mlx.mlx, game.mlx.mlx_win, 100, 100, 0xFFFFFF);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 17, 1L << 0, exit_hook, &game); 
	//mlx_hook(game.mlx.mlx_win, 15, 1L << 16, reduce_window, &game);
	//ウィンドウをXマーククリックで閉じる
	mlx_loop(game.mlx.mlx);
	/*
	draw_map(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 33, 1L << 5, exit_hook, &game);
	mlx_hook(game.mlx.mlx_win, 15, 1L << 16, reduce_window, &game);
	mlx_loop(game.mlx.mlx);
	*/
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
