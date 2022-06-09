/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:27:02 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 22:01:23 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	checker_image(char c, t_game *game)
{
	if (c == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->home, game->x * 32, game->y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->collect, game->x * 32, game->y * 32);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->asset.player1, game->x * 32, game->y * 32);
	else if (c == 'X')
		action_enemy(game);
}

void	draw(t_game *game)
{
	game->y = 0;
	game->number = 0;
	act_counter(game);
	while (game->y < (game->line_num - 1))
	{
		game->x = 0;
		while (game->x < game->line_char)
		{
			if (game->map[game->x + game->number] == '1')
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
					game->wall, game->x * 32, game->y * 32);
			}
			else
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
					game->back, game->x * 32, game->y * 32);
				checker_image(game->map[game->x + game->number], game);
			}
			game->x++;
		}
		game->y++;
		game->number = game->y * game->line_char;
	}
}