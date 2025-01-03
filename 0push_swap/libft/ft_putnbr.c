/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:46:07 by njulia-c          #+#    #+#             */
/*   Updated: 2025/01/03 20:20:09 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		count++;
		nb = nb / 10;
	}
	return (count + 1);
}

int	ft_putnbr(int nb)
{
	char	c;
	int		count;

	count = num_len(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr((nb / 10));
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (count);
}

// int	main(void)
// {
// 	int count = 0;

// 	count = ft_putnbr(100);
// 	ft_putnbr(count);
// 	return(0);
// }