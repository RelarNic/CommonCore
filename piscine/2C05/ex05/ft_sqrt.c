/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:00:00 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/03 14:17:23 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_recursive(int nb, int low, int high)
{
	int			mid;
	long long	square;

	mid = (high + low) / 2;
	square = mid * mid;
	if (low > high)
	{
		return (0);
	}
	if (nb == square)
	{
		return (mid);
	}
	else if (square < nb)
	{
		return (ft_sqrt_recursive(nb, mid + 1, high));
	}
	else
	{
		return (ft_sqrt_recursive(nb, low, mid - 1));
	}
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	return (ft_sqrt_recursive(nb, 0, nb));
}

/* int	main(void)
{
	printf("%d\n", ft_sqrt(144));
	return (0);
}*/