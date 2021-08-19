/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 15:03:31 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/19 17:57:24 by safoh         ########   odam.nl         */
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

char	*ft_chrcat(char *string, int c)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(string);
	dest = ft_calloc(len + 2, sizeof(char));
	ft_memcpy((void *)dest, string, len);
	if (string != NULL)
		free(string);
	dest[len] = c;
	return (dest);
}

char	*ft_argcat(int c, char *result, va_list ap)
{
	if (c == 'c')
		result = ft_chrcat(result, va_arg(ap, int));
	return (result);
}

static char	*printpars(const char *format, char *result, va_list ap)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			result = ft_argcat(format[i + 1], result, ap);
			i += 2;
		}
		else
		{
			result = ft_chrcat(result, format[i]);
			i++;
		}
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*result;
	size_t len;

	if(!format)
		return (0);
	va_start(ap, format);
	result = ft_calloc(1, sizeof(char));
	if (!result)
		return (0);
	result = printpars(format, result, ap);
	printf("\n%ld\n", sizeof(result));
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(result);
	va_end(ap);
	return (len);
}
