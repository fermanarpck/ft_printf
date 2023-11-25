/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farpacik <farpacik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:48:30 by farpacik          #+#    #+#             */
/*   Updated: 2022/12/15 13:48:31 by farpacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	control(char type, va_list list)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += fputchar(va_arg(list, int));
	else if (type == 's')
		len += fputstr(va_arg(list, char *));
	else if (type == 'd' || type == 'i')
		len += fputnbr(va_arg(list, int));
	else if (type == 'u')
		len += fputnbr(va_arg(list, unsigned));
	else if (type == 'p')
	{
		len += write(1, "0x", 2);
		len += fhexa(va_arg(list, unsigned long int), 'x');
	}
	else if (type == 'x')
		len += fhexa(va_arg(list, unsigned), type);
	else if (type == 'X')
		len += fhexa(va_arg(list, unsigned), type);
	else if (type == '%')
		len += fputchar('%');
	return (len);
}

int	ft_printf(const	char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i++], 1);
		else if (str[i] == '%')
		{
			len += control(str[++i], list);
			i++;
		}
	}
	va_end(list);
	return (len);
}