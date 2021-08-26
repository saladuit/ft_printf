/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:29:20 by safoh         #+#    #+#                 */
/*   Updated: 2021/08/26 18:29:39 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
