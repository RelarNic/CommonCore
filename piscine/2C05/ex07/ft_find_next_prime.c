/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:00:30 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/03 14:44:31 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i < nb / 2)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
	{
		return (nb);
	}
	if (nb <= 1)
	{
		return (2);
	}
	else
	{
		return (ft_find_next_prime(nb + 1));
	}
}

/*int	main(void)
{
	printf("%d\n", ft_find_next_prime(-13));
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(1));
	printf("%d\n", ft_find_next_prime(2147483647));
	printf("%d\n", ft_find_next_prime(-2147483648));
	printf("%d\n", ft_find_next_prime(00));
	printf("%d\n", ft_find_next_prime(-89));
	printf("%d\n", ft_find_next_prime(90));
	return (0);
}*/
