/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 13:54:02 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/12 13:54:48 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_numlen(int num)
{
	size_t	size;

	size = 0;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}
