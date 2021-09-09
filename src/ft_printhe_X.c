/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhe_X.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:26:48 by safoh         #+#    #+#                 */
/*   Updated: 2021/09/09 15:20:47 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printhe_X(size_t *len, unsigned int ui)
{
	char	*result;

	result = ft_uitoh(ui);
	ft_strtoupper(result);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result);
	free(result);
	return ;
}
