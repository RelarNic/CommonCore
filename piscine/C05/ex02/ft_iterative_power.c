/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:59:02 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/03 12:34:17 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
	{
		return (0);
	}
	if (nb == 0 && power == 0)
	{
		return (1);
	}
	result = 1;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
