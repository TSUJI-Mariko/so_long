/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:27:02 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/05 09:27:03 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
unsigned int get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

unsigned int rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

void draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char *target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

/*void draw_one_image(t_game *game, t_img *image, int x, int y)
{
	unsigned int color;
	int i;
	int j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = get_pixel(image, i, j);
			if (color != rgb_to_int(255, 255, 255, 255))
			{
				draw_pixel(game->mlx.mlx_img, x + i, y + j, color);
				//mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
				//mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, x + i, y + j, color);
			}
			i++;
		}
		j++;
	}
	//mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, image, x, y);
}*/
/*void draw_one_image(t_game *game, t_img *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, image, x * 32, y * 32);
}

void checker_image(char c, t_game *game)
{
    //if (c == '0')
		//draw_one_image(game, game->back, game->x, game->y * 31);
	if (c == 'E')
		draw_one_image(game, game->home, game->x, game->y * 31);
	else if (c == 'C')
		draw_one_image(game, game->collect, game->x, game->y * 31);
	else if (c == 'P')
		draw_one_image(game, game->player1, game->x, game->y * 31);  
	else if (c == 'X')  
		draw_one_image(game, game->asset->enemy[game->asset->enemy_img], game->x, game->y * 31);
}*/
void checker_image(char c, t_game *game)
{
    //if (c == '0')
		//draw_one_image(game, game->back, game->x, game->y * 31);
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
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, 
		game->asset.enemy1, game->x * 32, game->y * 32);
}


/*
void draw(t_game *game)
{
	int z;

	z = 0;
	game->y = 0;
    game->x = -32;
	game->number = 0;
	while (game->y < (game->line_num - 1))
	{
		z = 0;
		while (z < game->line_char)	
		{
			if (game->map[z + game->number] == '1')
			{
				draw_one_image(game, game->wall, game->x += 32, game->y * 31);
			}
			else 
                draw_one_image(game, game->back, game->x += 32, game->y * 31);
                checker_image(game->map[z + game->number], game);
			z++;
		}
		game->y++;
		game->number = game->y * game->line_char;
	}
	//mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.mlx_img, 0, 0);
}*/
void draw(t_game *game)
{
	game->y = 0;
	game->number = 0;
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
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, 
				game->back, game->x * 32, game->y * 32);
                checker_image(game->map[game->x + game->number], game);
			game->x++;
		}
		game->y++;
		game->number = game->y * game->line_char;
	}
	//mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.mlx_img, 0, 0);
}

/*
void destroy_enemy(t_game *game)
{
	int i;

	i = 0;
	while (i < ASSETS)
	{
		mlx_destroy_image(game->mlx.mlx, game->asset->enemy[i]);
		i++;
	}
	free(game->asset->enemy);
}
*/
/*
void draw(t_game *game)
{

	int z;

	game->x = -32;
	game->y = 0;
	game->number = 0;
	z = 0;
	while (game->y < (game->line_num - 1))
	{
		z = 0;
		while (z < game->line_char)	
		{
			if (game->map[z + game->number] == '1')
			{
				//draw_square(game, game->back, game->x += 16, game->y * 15);
				//draw_one_image(game, game->wall, game->x += 32, game->y * 31);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->wall, game->x += 32, game->y * 32);
			}
			else if (game->map[z + game->number] == '0')
				//draw_one_image(game, game->back, game->x += 32, game->y * 31);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->back, game->x += 32, game->y * 32);
			else if (game->map[z + game->number] == 'E')
				//draw_one_image(game, game->home, game->x += 32, game->y * 31);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->home, game->x += 32, game->y * 32);
			else if (game->map[z + game->number] == 'C')
				//draw_one_image(game, game->collect, game->x += 32, game->y * 31);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->collect, game->x += 32, game->y * 32);
			else if (game->map[z + game->number] == 'P')
				//draw_one_image(game, game->person1, game->x += 32, game->y * 31);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->person1, game->x += 32, game->y * 32);
			z++;
		}
		game->y++;
		game->number = game->y * game->line_char;
	}
	//mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.mlx_img, 0, 0);
}*/


