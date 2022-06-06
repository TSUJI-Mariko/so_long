/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:58:45 by mtsuji            #+#    #+#             */
/*   Updated: 2022/05/30 11:58:47 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_wall(char *line, char *map_all)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			error_message("map is'nt surrounded by walls", map_all);
		}
		i++;
	}
}
void	check_elements(char *map_all)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (map_all[i])
	{
		if (map_all[i] != '1' && map_all[i] != '0' 
            && map_all[i] != 'E' && map_all[i] != 'P'
			&& map_all[i] != 'C' && map_all[i] != 'X')
			error_message("there is another word", map_all);
		else if (map_all[i] == 'P')
			p++;
		i++;
	}
	if (p > 1)
		error_message("not only one person on map", map_all);

}

void    error_message(char *message, char *map)
{
    ft_printf("%s\n", message);
    free(map);
    exit(1);
}
/*
void checker_enemy(t_game *game)
{
	int i;

	i = 0;
	while (i < ASSETS)
	{
		if (game->asset->enemy[i] == NULL)
			error_message("enemy image not loaded!", game->map);
		i++;
	}
}
*/
void    free_asset(t_game *game)
{
    mlx_destroy_image(game->mlx.mlx, game->home);
    mlx_destroy_image(game->mlx.mlx, game->back);
    mlx_destroy_image(game->mlx.mlx, game->wall);
    mlx_destroy_image(game->mlx.mlx, game->collect);
	mlx_destroy_image(game->mlx.mlx, game->asset.player1);    
    mlx_destroy_image(game->mlx.mlx, game->asset.player2);
	mlx_destroy_image(game->mlx.mlx, game->asset.player3);
	mlx_destroy_image(game->mlx.mlx, game->asset.player4);
    mlx_destroy_image(game->mlx.mlx, game->asset.enemy1);
    mlx_destroy_image(game->mlx.mlx, game->asset.enemy2);
    mlx_destroy_image(game->mlx.mlx, game->asset.enemy3);
    mlx_destroy_image(game->mlx.mlx, game->asset.enemy4);    
}
