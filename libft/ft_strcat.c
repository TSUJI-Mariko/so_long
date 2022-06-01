/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:11:51 by mtsuji            #+#    #+#             */
/*   Updated: 2022/05/30 11:11:54 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
	unsigned int	a;
	unsigned int len;
	a = 0;
	
	len = ft_strlen(dest);
	while (src[a])
    {
        dest[a + len] = src[a];
        a++;
    }
    dest[a + len] = 0;
	return (dest);
}
