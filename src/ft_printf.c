/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 15:03:31 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 19:01:46 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

static void	printpars(const char *format, size_t *len, va_list ap)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_cnvspc(format[i + 1], len, ap);
			i += 2;
		}
		else
		{
			ft_printchr(len, format[i]);
			i++;
		}
	}
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	len = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	printpars(format, &len, ap);
	va_end(ap);
	return (len);
}
