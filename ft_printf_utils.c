/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehyildi <mehyildi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:26:29 by mehyildi          #+#    #+#             */
/*   Updated: 2023/02/15 16:08:02 by mehyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	sum;

	sum = 0;
	while (!str)
	{
		sum += write(1, "(null)", 6);
		return (sum);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		sum++;
	}
	return (sum);
}

int	ft_putnbr(long double nbr, int base, int is_upper)
{
	int	sum;

	sum = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		sum++;
	}
	if (nbr >= base)
		sum += ft_putnbr(((unsigned long)nbr / base), base, is_upper);
	if (is_upper == 1)
		write(1, &UPPER_BASE[(unsigned long)nbr % base], 1);
	else
		write(1, &LOWER_BASE[(unsigned long)nbr % base], 1);
	return (sum);
}

int	ft_putptr(long double nbr, int base, int is_upper)
{
	int	sum;

	sum = 0;
	sum += ft_putstr("0x");
	sum += ft_putnbr(nbr, base, is_upper);
	return (sum);
}
