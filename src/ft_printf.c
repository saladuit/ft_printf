/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 15:03:31 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/18 14:40:36 by safoh         ########   odam.nl         */
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

char	*ft_chrcat(char *string, const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(string);
	dest = calloc(len + 2, sizeof(char));
	ft_memcpy((void *)dest, string, len);
	free(string);
	ft_memcpy((void *)&dest[len], src, 1);
	return (dest);
}

static char	*printpars(const char *format, char *result)
{
	size_t	i;

	while (format[i] != '\0')
	{
		result = ft_chrcat(result, &format[i]);
		i++;
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
	result = calloc(1, sizeof(char));
	result = printpars(format, result);
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(result);
	va_end(ap);
	return (len);
}
