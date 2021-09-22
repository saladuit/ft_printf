/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhex.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:27:18 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/22 11:41:16 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libs/libft/include/libft.h"

void	ft_printhex(size_t *len, unsigned int ui)
{
	char	*result;

	result = ft_uitoh(ui);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result);
	free(result);
	return ;
}
