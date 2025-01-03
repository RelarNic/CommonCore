/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:52:12 by njulia-c          #+#    #+#             */
/*   Updated: 2025/01/03 20:19:50 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long long nb, const char *base)
{
	char	c;
	int		min_int_flag;
	int		count;

	count = 0;
	min_int_flag = 0;
	if (nb == -2147483648)
	{
		min_int_flag = 1;
		nb++;
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= ft_strlen(base))
		count += ft_putnbr_base(nb / ft_strlen(base), base);
	if (min_int_flag)
		c = base[(nb % ft_strlen(base)) - 1];
	else
		c = base[nb % ft_strlen(base)];
	count += write(1, &c, 1);
	return (count);
}
