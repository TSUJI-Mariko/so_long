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
    free(game);
    exit(1);
}

int key_hook(int keycord, t_game *game)
{
    if (keycord == 65307)
        exit_hook(game);
    return (1);
}