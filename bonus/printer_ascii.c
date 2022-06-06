/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:31:30 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 23:33:34 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	printer_ascii(char *filename)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	gnl = get_next_line(fd, &line);
	while (gnl)
	{
		ft_printf("%s\n", line);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	close(fd);
	free(line);
}

void	game_clear(t_game *game)
{
	printer_ascii("./bonus/clear_ascii.txt");
	exit_hook(game);
}

void	game_over(t_game *game)
{
	printer_ascii("./bonus/game_over_ascii.txt");
	exit_hook(game);
}
