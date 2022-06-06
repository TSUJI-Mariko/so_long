/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:46:42 by mtsuji            #+#    #+#             */
/*   Updated: 2022/05/25 11:46:44 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int exit_hook(t_game *game)
{
    free(game->map);
    free_asset(game);
    exit(0);
}

int	reduce_window(t_game *game)
{
	draw(game);
	return (1);
}

int key_hook(int keycord, t_game *game)
{
    if (keycord == 0xff1b)
        exit_hook(game);
    if (keycord == 0x64)
        right(game);
    if (keycord == 0x61)
        left(game);
    if (keycord == 0x77)
        up(game);
    if (keycord == 0x73)
        down(game);
    return (1);
}