/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:45:38 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/10 17:04:07 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	act_counter(t_game *game)
{
	if (game->enemy_count < 3)
		game->enemy_count++;
	else
		game->enemy_count = 0;
}

void	checker_enemy(t_img **enemy, t_game *game)
{
	int	i;

	i = 0;
	while (i < ASSETS)
	{
		if (enemy[i] == NULL)
			error_message("enemy image not loaded!", game->map);
		i++;
	}
}

void	action_enemy(t_game *game)
{
	t_img	*enemy[4];

	enemy[0] = game->asset.enemy1;
	enemy[1] = game->asset.enemy2;
	enemy[2] = game->asset.enemy3;
	enemy[3] = game->asset.enemy4;
	checker_enemy(enemy, game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		enemy[game->enemy_count], game->x * 32, game->y * 32);
}
