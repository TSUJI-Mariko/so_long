/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:55:52 by mtsuji            #+#    #+#             */
/*   Updated: 2022/04/25 18:36:04 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

int	ft_atoi(const char *str)
{
	long	atoi;
	int		negative;

	atoi = 0;
	negative = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' \
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + *str - 48;
		str++;
		if (atoi * negative > 2147483647)
			put_error();
		else if (atoi * negative < -2147483648)
			put_error();
	}
	return ((int)atoi * negative);
}
