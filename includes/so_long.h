/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:47:57 by mtsuji            #+#    #+#             */
/*   Updated: 2022/05/25 11:47:59 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define HEIGHT 400
# define WIDTH 2000

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_mlx
{
    void    *mlx_win;
    void    *mlx;
    t_img   *mlx_img;
} t_mlx;


typedef struct s_game
{
    t_mlx   mlx;    
    int map_height;
    int map_width;
    int fd;
    int line_char;
    int line_num;
    int line_end;
    int number;
    int x;
    int y;
    char *map;
    t_img   img;
    t_img   player;
    t_img   *home;
    t_img   *back;
    t_img   *wall;
    t_img   *collect;
    t_img   *person1;
    t_img   ground;
} t_game;


//key_hook
int exit_hook(t_game *game);
int key_hook(int keycode, t_game *game);

//error_message
void    error_message(char *message, char *map);
#endif
