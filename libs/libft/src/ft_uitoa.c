/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 11:46:29 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:50:03 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_uitoa(unsigned int nb)
{
	size_t		len;
	char		*result;
	size_t		neg;
	long long	buffer;

	buffer = nb;
	len = ft_numlen(buffer);
	neg = 0;
	result = calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	if (buffer < 0)
	{
		buffer = -buffer;
		*result = '-';
		neg = 1;
	}
	while (len > neg)
	{
		len--;
		result[len] = (buffer % 10) + '0';
		buffer /= 10;
	}
	return (result);
}
