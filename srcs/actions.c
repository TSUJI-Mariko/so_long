/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:26:51 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/03 13:26:53 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void right(t_game *game)
{ 
   char *ptr;
    int i;

   ptr = ft_strchr(game->map, 'P');
   i = 0;
   if(ptr[i + 1]  != '1' && ptr[i + 1] != 'E')
   {
       if (ptr[i + 1] == 'C')
            game->star--;
       ptr[i] = '0';
       ptr[i + 1] = 'P';
       game->move++;
        ft_printf("steps:%d\n",game->move);
        draw(game);
   }
    
    else if (game->star == 0 && ptr[i + 1] == 'E')
    {
        printer_clear("./bonus/clear_ascii.txt");
        exit_hook(game);
    }
}

void left(t_game *game)
{
    int i;

   i = 0;
    while (game->map[i] != 'P')
        i++;
   if(game->map[i - 1]  != '1' && game->map[i - 1] != 'E')
   {
       if (game->map[i - 1] == 'C')
            game->star--;
       game->map[i] = '0';
       game->map[i - 1] = 'P';
       game->move++;
        ft_printf("steps:%d\n",game->move);
        //mlx_destroy_image(game->mlx.mlx, game->person1);
        //load_image(game, &game->person1, "./img/Mario1.xpm");
        //mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
        draw(game);
   }
    else if (game->star == 0 && game->map[i - 1] == 'E')
    {
        printer_clear("./bonus/clear_ascii.txt");
        exit_hook(game);
    }
}

void up(t_game *game)
{
 int i;

   i = 0;
    while (game->map[i] != 'P')
        i++;
    if (game->map[i - game->line_char] != '1' 
        && game->map[i - game->line_char] != 'E')
    {
        if (game->map[i - game->line_char] == 'C')
            game->star--;
        game->map[i] = '0';
       game->map[i - game->line_char] = 'P';
       game->move++;
       ft_printf("steps:%d\n",game->move);
        draw(game);
    }
    else if(game->star == 0 
        && game->map[i - game->line_char] == 'E')
    {
        printer_clear("./bonus/clear_ascii.txt");
        exit_hook(game);
    }
}

void down(t_game *game)
{
     int i;

   i = 0;
    while (game->map[i] != 'P')
        i++;
    if (game->map[i + game->line_char] != '1' 
        && game->map[i + game->line_char] != 'E')
    {
        if (game->map[i + game->line_char] == 'C')
            game->star--;
        game->map[i] = '0';
       game->map[i + game->line_char] = 'P';
       game->move++;
        ft_printf("steps:%d\n",game->move);
        draw(game);
    }
    else if (game->star == 0 
        && game->map[i + game->line_char] == 'E')
    {
        printer_clear("./bonus/clear_ascii.txt");
        exit_hook(game);
    }
}
