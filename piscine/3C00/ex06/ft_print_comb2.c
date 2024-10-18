/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:32:49 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/08 16:48:31 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	primer;
	int	segun;

	primer = 00;
	while (primer <= 98)
	{
		segun = primer + 1;
		while (segun <= 99)
		{
			if (primer < 10)
				write(1, "0", 1);
			ft_putnbr(primer);
			write(1, " ", 1);
			if (segun < 10)
				write(1, "0", 1);
			ft_putnbr(segun);
			if (!(primer == 98 && segun == 99))
				write(1, ", ", 2);
			segun++;
		}
		primer++;
	}
}
