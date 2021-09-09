/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoh.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:58:42 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 19:23:00 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	hexlen(unsigned long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_ultoh(unsigned long n)
{
	char	*result;
	char	*hex;
	size_t	len;
	size_t	i;

	len = hexlen(n);
	i = 0;
	result = calloc(len + 1, sizeof(char));
	hex = ft_strdup("0123456789abcdef");
	while (i < len)
	{
		result[len - 1] = hex[n % 16];
		n /= 16;
		len--;
	}
	free(hex);
	return (result);
}