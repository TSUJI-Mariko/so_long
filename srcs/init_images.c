/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:43:13 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 22:45:08 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}

void	player_setting(t_game *game)
{
	game->player_count = 0;
	load_image(game, &game->asset.player1, "./img/Mario1.xpm");
	//load_image(game, &game->asset.player2, "./img/Mario2.xpm");
	//load_image(game, &game->asset.player3, "./img/Mario3.xpm");
	//load_image(game, &game->asset.player4, "./img/Mario4.xpm");
	//load_image(game, &game->asset.player_left, "./img/Mario_left.xpm");
}

void	enemy_setting(t_game *game)
{
	game->enemy_count = 0;
	load_image(game, &game->asset.enemy1, "./img/cactus1.xpm");
	load_image(game, &game->asset.enemy2, "./img/cactus2.xpm");
	load_image(game, &game->asset.enemy3, "./img/cactus3.xpm");
	load_image(game, &game->asset.enemy4, "./img/cactus4.xpm");
}