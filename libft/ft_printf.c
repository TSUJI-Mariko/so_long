/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:44:30 by mtsuji            #+#    #+#             */
/*   Updated: 2022/06/06 23:10:16 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	to_hexadecimal(unsigned long long nb, char conversion)
{
	int	byte;

	byte = 0;
	if (nb <= 9)
		byte += ft_putchar(nb + '0');
	else if (nb >= 16)
	{
		byte += to_hexadecimal(nb / 16, conversion);
		byte += to_hexadecimal(nb % 16, conversion);
	}
	else
	{
		if (conversion == 'x')
			byte += ft_putchar(nb - 10 + 'a');
		else if (conversion == 'X')
			byte += ft_putchar(nb - 10 + 'A');
	}
	return (byte);
}

int	print_pointer(void *nb, char format)
{
	int				byte;
	void			*ptr;
	unsigned long	nbr;

	ptr = nb;
	nbr = (unsigned long) ptr;
	byte = 0;
	format = 'x';
	byte += ft_putstr("0x");
	return (byte += to_hexadecimal(nbr, format));
}

void	conversion_checker(char *format, t_count *count)
{
	if (format[count->index] == 'c')
		count->byte += ft_putchar(va_arg(count->argument, int));
	else if (format[count->index] == 's')
		count->byte += ft_putstr(va_arg(count->argument, char *));
	else if (format[count->index] == 'p')
		count->byte += print_pointer(va_arg(count->argument, void *),
				format[count->index]);
	else if (format[count->index] == 'd' || format[count->index] == 'i')
		count->byte += ft_putnbr(va_arg(count->argument, int));
	else if (format[count->index] == 'u')
		count->byte += ft_putnbr(va_arg(count->argument, unsigned int));
	else if (format[count->index] == 'x' || format[count->index] == 'X')
		count->byte += to_hexadecimal(va_arg(count->argument, unsigned int),
				format[count->index]);
	else if (format[count->index] == '%')
		count->byte += ft_putchar('%');
}

void	print_before_sign(char *format, t_count *count)
{
	if (format[count->index] != '%')
		count->byte += ft_putchar(format[count->index]);
	if (format[count->index] == '%')
	{
		count->index++;
		conversion_checker(format, count);
	}
}

int	ft_printf(const char *format, ...)
{
	t_count	count;

	count.byte = 0;
	count.index = 0;
	va_start(count.argument, format);
	while (format[count.index])
	{
		print_before_sign((char *)format, &count);
		count.index++;
	}
	va_end(count.argument);
	return (count.byte);
}
