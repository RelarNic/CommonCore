/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:59:43 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/03 12:56:27 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonnacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index <= 1)
	{
		return (index);
	}
	else
	{
		return (ft_fibonnacci(index - 1) + ft_fibonnacci(index - 2));
	}
}

/*int	main(void)
{
	printf("%d\n", ft_fibonnacci(13));
	return (0);
}
*/