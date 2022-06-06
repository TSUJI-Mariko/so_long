/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:26:51 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 22:28:38 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	right(t_game *game)
{
	char	*ptr;
	int		i;

	ptr = ft_strchr(game->map, 'P');
	i = 0;
	if (ptr[i + 1] != '1' && ptr[i + 1] != 'E')
	{
		if (ptr[i + 1] == 'C')
			game->star--;
		if (ptr[i + 1] == 'X')
			game_over(game);
		ptr[i] = '0';
		ptr[i + 1] = 'P';
		game->move++;
		ft_printf("steps:%d\n", game->move);
		mlx_destroy_image(game->mlx.mlx, game->asset.player1);
		load_image(game, &game->asset.player1, "./img/Mario1.xpm");
		draw(game);
	}
	if (game->star == 0 && ptr[i + 1] == 'E')
		game_clear(game);
}

void	left(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i - 1] != '1' && game->map[i - 1] != 'E')
	{
		if (game->map[i - 1] == 'C')
			game->star--;
		if (game->map[i - 1] == 'X')
			game_over(game);
		game->map[i] = '0';
		game->map[i - 1] = 'P';
		game->move++;
		ft_printf("steps:%d\n", game->move);
		mlx_destroy_image(game->mlx.mlx, game->asset.player1);
		load_image(game, &game->asset.player1, "./img/Mario_left.xpm");
		draw(game);
	}
	if (game->star == 0 && game->map[i - 1] == 'E')
		game_clear(game);
}

void	up(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i - game->line_char] != '1'
		&& game->map[i - game->line_char] != 'E')
	{
		if (game->map[i - game->line_char] == 'C')
			game->star--;
		if (game->map[i - game->line_char] == 'X')
			game_over(game);
		game->map[i] = '0';
		game->map[i - game->line_char] = 'P';
		game->move++;
		ft_printf("steps:%d\n", game->move);
		draw(game);
	}
	if (game->star == 0
		&& game->map[i - game->line_char] == 'E')
		game_clear(game);
}

void	down(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i + game->line_char] != '1'
		&& game->map[i + game->line_char] != 'E')
	{
		if (game->map[i + game->line_char] == 'C')
			game->star--;
		if (game->map[i + game->line_char] == 'X')
			game_over(game);
		game->map[i] = '0';
		game->map[i + game->line_char] = 'P';
		game->move++;
		ft_printf("steps:%d\n", game->move);
		draw(game);
	}
	if (game->star == 0
		&& game->map[i + game->line_char] == 'E')
		game_clear(game);
}
