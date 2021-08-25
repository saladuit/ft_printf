/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 17:29:41 by saladin       #+#    #+#                 */
/*   Updated: 2021/08/20 12:09:52 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "/home/saladuit/Documents/Projects_Codam/ft_printf/libs/libft/include/libft.h"

int	ft_printf(const char *format, ...);
char	*mr_asprintf(const char *format, va_list ap);
char	*cvrtchar(char *s1, const char *s2);
char	*cvrtint(char *s1, int num);
char	*cvrtstr(char *s1, char *s2);

#endif
