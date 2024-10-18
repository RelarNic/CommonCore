/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:51:11 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/10 12:17:54 by njulia-c         ###   ########.fr       */
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

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (nb == 0 && power == 0)
	{
		return (1);
	}
	if (power == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}

int	rev_repe_crec(int n, int numdig)
{
	int	digitos[10];
	int	i;

	i = 0;
	while (i < numdig)
	{
		digitos[i] = n % 10;
		n = n / 10;
		i++;
	}
	i = 0;
	while (i < numdig - 1)
	{
		if (digitos[i] <= digitos[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	int	primer;
	int	max;
	int	i;

	max = 9;
	i = 1;
	primer = 1;
	while (n > i)
	{
		max = max * 10 + 9;
		i++;
	}
	while (primer <= max)
	{
		if (!(rev_repe_crec(primer, n)))
		{
			if (primer < ft_recursive_power(10, n - 1))
				write(1, "0", 1);
			ft_putnbr(primer);
			write(1, ", ", 2);
		}
		primer++;
	}
	write(1, "\b\b", 2);
}
