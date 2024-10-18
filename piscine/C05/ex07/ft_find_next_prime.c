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

int	ft_is_prime_recursive(int nb, int divisor)
{
	if (divisor <= 1)
	{
		return (1);
	}
	if (nb % divisor == 0)
	{
		return (0);
	}
	return (ft_is_prime_recursive(nb, divisor - 1));
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
	{
		return (0);
	}
	return (ft_is_prime_recursive(nb, nb / 2));
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
	{
		return (nb);
	}
	else
	{
		return (ft_find_next_prime(nb + 1));
	}
}

/*int	main(void)
{
	printf("%d\n", ft_find_next_prime(2019));
	return (0);
}*/