/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 15:03:31 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/18 13:28:11 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

//GOAL Write a library that contains ft_printf, a function
//		that will mimic the real printf
//		It will manage the following conversions: cspdiuxX%

char	*cvrtstr(char *s1, char *s2)
{
	size_t len_s1;
	size_t len_s2;
	char *dest;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = calloc(len_s1 + len_s2 + 1, sizeof(char));
	ft_memcpy((void *)dest, s1, len_s1);
	ft_memcpy((void *)&dest[len_s1], s2, len_s2);
	return (dest);
}

char	*cvrtint(char *s1, int num) {
	size_t len_s1;
	size_t len_num;
	char *dest;
	char *s2;

	len_s1 = ft_strlen(s1);
	len_num = ft_numlen(num);
	if (num == 0)
		len_num = 1;
	if (num < 0)
		len_num += 1;
	dest = calloc(len_s1 + len_num + 1, sizeof(char));
	ft_memcpy((void *)dest, s1, len_s1);
	s2 = ft_itoa(num);
	puts(s2);
	ft_memcpy((void *)&dest[len_s1], s2, len_num);
	return (dest);
}

char	*cvrtchar(char *s1, const char *s2) {
	size_t len_s1;
	char *dest;

	len_s1 = ft_strlen(s1);
	dest = calloc(len_s1 + 2, sizeof(char));
	ft_memcpy((void *)dest, s1, len_s1);
	ft_memcpy((void *)&dest[len_s1], s2, 1);
	return (dest);
}

char	*mr_asprintf(const char *format, va_list ap)
{
	size_t i;
	size_t size;
	char *result;

	i = 0;
	result = NULL;
	size = ft_strlen(format);
	result = calloc(size + 1, sizeof(char));
	while (format[i])
	{
		if (format [i] == '%')
		{
	    	i++;
	    	if (format[i] == 'c')
			{
	      		result = cvrtchar(result, &format[i]);
	      		i++;
	    	}
	    	if (format[i] == 's')
			{
        		result = cvrtstr(result, va_arg(ap, char *));
        		i += 2;
      		}
			else if (format[i] == 'i') {
				result = cvrtint(result, va_arg(ap, int));
				i += 2;
			}
		}
		else 
		{
			result = cvrtchar(result, &format[i]);
			i++;
		}
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char *string;

	if(!format)
		return (0);
	va_start(ap, format);
	string = mr_asprintf(format, ap);
	ft_putstr_fd(string, 1);
	va_end(ap);
	return (ft_strlen(string));
}
