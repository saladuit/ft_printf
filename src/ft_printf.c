/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 15:03:31 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:05:29 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

//GOAL Write a library that contains ft_printf, a function
//		that will mimic the real printf
//		It will manage the following conversions: cspdiuxX%
//CONVERSION:
//		• %c print a single character. | cvrtchar
//		• %s print a string of characters. | cvrtstr
//		• %p The void * pointer argument is printed in hexadecimal. | cvrtp
//		• %d print a decimal (base 10) number. | cvrtd
//		• %i print an integer in base 10. | cvrti
//		• %u print an unsigned decimal (base 10) number. | cvrtu
//		• %x print a number in hexadecimal (base 16). | cvrtx
//		• %% print a percent sign.

//INPUT a certain format & variadic argument(s)
//LOOP through format until the end reach the of format
//ADD each character to string unless %
//IF we find a %
//LOOP until we find conversion specifier
//CALL corresponding conversion function
//ADD returned buffer to string
//PRINT string
//RETURN length

void	ft_printpct(size_t *len)
{
	ft_putchar_fd('%', 1);
	*len += 1;
	return ;
}

void	ft_printpnt(size_t *len, unsigned long ul)
{
	char	*result;

	ft_putstr_fd("0x", 1);
	result = ft_ultoh(ul);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result) + 2;
	free(result);
	return ;
}

void	ft_printheX(size_t *len, unsigned int ui)
{
	char	*result;

	result = ft_uitoh(ui);
	ft_strtoupper(result);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result);
	free(result);
	return ;
}

void	ft_printhex(size_t *len, unsigned int ui)
{
	char	*result;

	result = ft_uitoh(ui);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result);
	free(result);
	return ;
}

void	ft_printudec(size_t *len, unsigned int n)
{
	ft_putuint_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}

void	ft_printdec(size_t *len, int n)
{
	ft_putnbr_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}

void	ft_printstr(size_t *len, char *string)
{
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		*len += ft_strlen("(null)");
	}
	ft_putstr_fd(string, 1);
	*len += ft_strlen(string);
	return ;
}

void	ft_printchr(size_t *len, int c)
{
	ft_putchar_fd(c, 1);
	*len += 1;
	return ;
}

void	ft_cnvspc(int c, size_t *len, va_list ap)
{
	if (c == 'c')
		ft_printchr(len, va_arg(ap, int));
	else if (c == 's')
		ft_printstr(len, va_arg(ap, char*));
	else if (c == 'i' || c == 'd')
		ft_printdec(len, va_arg(ap, int));
	else if (c == 'u')
		ft_printudec(len, va_arg(ap, unsigned int));
	else if (c == 'x')
		ft_printhex(len, va_arg(ap, unsigned int));
	else if (c == 'X')
		ft_printheX(len, va_arg(ap, unsigned int));
	else if (c == 'p')
		ft_printpnt(len, va_arg(ap, unsigned long));
	else if (c == '%')
		ft_printpct(len);
	return ;
}

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
	size_t len;

	len = 0;
	if(!format)
		return (0);
	va_start(ap, format);
	printpars(format, &len, ap);
	va_end(ap);
	return (len);
}
