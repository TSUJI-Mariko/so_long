/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:43:13 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/10 16:54:44 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_image(t_game *game, t_img **image, char *filename)
{
	int	height;
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
}

void	enemy_setting(t_game *game)
{
	game->enemy_count = 0;
	load_image(game, &game->asset.enemy[0], "./img/cactus1.xpm");
	load_image(game, &game->asset.enemy[1], "./img/cactus2.xpm");
	load_image(game, &game->asset.enemy[2], "./img/cactus3.xpm");
	load_image(game, &game->asset.enemy[3], "./img/cactus4.xpm");
}
