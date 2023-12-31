/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farpacik <farpacik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:48:21 by farpacik          #+#    #+#             */
/*   Updated: 2022/12/15 13:48:22 by farpacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fputchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	fputstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}

int	fputnbr(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		len += fputnbr(nb / 10);
		len += fputnbr(nb % 10);
	}
	else if (nb < 10)
		len += fputchar(nb + '0');
	return (len);
}

int	fhexa(unsigned long int nb, char flag)
{
	const char	lowerbase[] = "0123456789abcdef";
	const char	upperbase[] = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (nb >= 16)
	{
		len += fhexa(nb / 16, flag);
		len += fhexa(nb % 16, flag);
	}
	else if (nb < 16 && flag == 'x')
		len += write(1, &lowerbase[nb % 16], 1);
	else if (nb < 16 && flag == 'X')
		len += write(1, &upperbase[nb % 16], 1);
	return (len);
}