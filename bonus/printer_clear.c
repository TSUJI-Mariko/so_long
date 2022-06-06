/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:04 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/05 14:05:06 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void printer_ascii(char *filename)
{
    int fd;
    char *line;
    int gnl;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return;
    
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
