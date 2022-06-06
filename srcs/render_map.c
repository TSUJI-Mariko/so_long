/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:35:59 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 22:40:10 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map2(t_game *game, char *map_all)
{
	if ( ft_strchr(map_all, 'E') == NULL
		|| ft_strchr(map_all, 'P') == NULL
		|| ft_strchr(map_all, 'C') == NULL )
		error_message("not E,P or C", map_all);
	if (game->line_char -1 == game->line_num)
		error_message("it's square map!", map_all);
	check_elements(map_all);
	game->map = ft_strdup(map_all);
	game->fd = close(game->fd);
	game->map_width = game->line_char * 32;
	game->map_height = (game->line_num - 1) * 32;
	free(map_all);
}

void	deal_line(int ret, char *line, t_game *game, char *map_all)
{

	while (ret > 0)
	{
		game->line_num++;
		game->line_end = ft_strlen(line) - 1;
		if (line[0] != '1' ||line[game->line_end] != '1')
			error_message("wall is not surrounded by wall '1'", map_all);
		ft_strcat(map_all, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if ((ret != 0) && ft_strlen(line) != game->line_char)
			error_message("mapping_error", map_all);
	}
	if (ret == 0)
	{
		game->line_num++;
		check_wall(line,map_all);
		ft_strcat(map_all, line);
		free(line);
		line = 0;
	}
}

char	init_map(t_game *game, char *map)
{
	char	*line;
	int		ret;
	char	*map_all;

	game->move = 0;
	game->line_num = 0;
	map_all = malloc(sizeof(char *) * 10000);
	*map_all = 0;
	game->fd = open(map, O_RDONLY);
	if (game->fd == -1)
		error_message("fd is '-1'", map_all);
	line = 0;
	ret = get_next_line(game->fd, &line);
	check_wall(line, map_all);
	game->line_char = ft_strlen(line);
	deal_line(ret, line, game, map_all);
	init_map2(game, map_all);
	return (1);
}
