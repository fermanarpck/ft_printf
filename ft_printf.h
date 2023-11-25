/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farpacik <farpacik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:48:35 by farpacik          #+#    #+#             */
/*   Updated: 2022/12/15 13:48:36 by farpacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H	
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	control(char type, va_list list);
int	ft_printf(const char *str, ...);
int	fputchar(char c);
int	fputstr(char *str);
int	fputnbr(long nb);
int	fhexa(unsigned long int nb, char flag);
#endif