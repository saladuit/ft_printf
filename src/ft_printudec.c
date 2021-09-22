/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printudec.c                                  |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:27:52 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/22 11:41:37 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libs/libft/include/libft.h"

void	ft_printudec(size_t *len, unsigned int n)
{
	ft_putuint_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}
