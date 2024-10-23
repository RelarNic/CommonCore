/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:59:46 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/23 11:59:53 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	print_str(const char *s);
int	ft_putnbr_base(long nb, const char *base);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_strlen(const char *str);
int	ft_putvoid_hex(unsigned long p);

#endif