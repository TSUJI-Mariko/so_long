/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:54:24 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 22:46:27 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_structure(t_game *game)
{
	int i;

	game->star = 0;
    i = 0;
    while (game->map[i])
    {
        if (game->map[i] == 'C')
            game->star++;
        i++;
    }
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, game->map_width, game->map_height, "So_long"); 
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx, game->map_width, game->map_height);
	image_setting(game);
	player_setting(game);
	enemy_setting(game);
	return (1);
}

int main(int argc, char **argv)
{
	t_game game;
	//t_asset asset;
	//void *mlx_new;
	//void *mlx_win;

	if (argc != 2)
		return (0);
	init_map(&game, argv[1]);
	init_structure(&game);
	//draw(&game);
	mlx_loop_hook(game.mlx.mlx, render, &game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 17, 1L << 0, exit_hook, &game); 
	//mlx_hook(game.mlx.mlx_win, 15, 1L << 16, reduce_window, &game);
	//ウィンドウをXマーククリックで閉じる
	mlx_loop(game.mlx.mlx);
}
