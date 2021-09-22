/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                     |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 13:54:02 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/22 14:43:11 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//size_t	ft_numlen(long long num)
//{
//	size_t	size;
//
//	size = 0;
//	if (num == 0)
//		return (1);
//	if (num < 0)
//		size++;
//	while (num)
//	{
//		num /= 10;
//		size++;
//	}
//	return (size);
//}

size_t	ft_numlen(long long num)
{
	if (num < 0)
		num = -num;
	if (num < 10)
		return (1);
	if (num < 100)
		return (2);
	if (num < 1000)
		return (3);
	if (num < 10000)
		return (4);
	if (num < 100000)
		return (5);
	if (num < 1000000)
		return (6);
	return ((ft_numlen(num / 1000000)) + 6);
}

