/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:00:16 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/06 12:47:04 by njulia-c         ###   ########.fr       */
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

/*int	main(void)
{
	printf("%d\n", ft_is_prime(-13));
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(-2147483648));
	printf("%d\n", ft_is_prime(00));
	printf("%d\n", ft_is_prime(-89));
	printf("%d\n", ft_is_prime(90));
	return (0);
}*/
