/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:26:40 by mtsuji            #+#    #+#             */
/*   Updated: 2021/05/31 22:26:44 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long nb)
{
	static int	byte;
	int			byte_minus;

	byte = 0;
	byte_minus = 0;
	if (nb < 0)
	{
		byte_minus = ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	byte += ft_putchar(nb + 48);
	return (byte + byte_minus);
}