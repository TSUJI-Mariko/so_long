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
			ft_printf("%s\n", "map is'nt surrounded by walls '1'");
			free(map_all);
			exit(1);
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
		if (map_all[i] != '1' && map_all[i] != '0' &&
			map_all[i] != 'E' && map_all[i] != 'P'
			&& map_all[i] != 'C')
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
    ft_putstr_fd(message, 2);
    free(map);
    exit(1);
}