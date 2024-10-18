/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:34:48 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/08 16:35:52 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	primer;
	char	segun;
	char	tercer;

	primer = '0';
	while (primer <= '7')
	{
		segun = primer + 1;
		while (segun <= '8')
		{
			tercer = segun + 1;
			while (tercer <= '9')
			{
				write(1, &primer, 1);
				write(1, &segun, 1);
				write(1, &tercer, 1);
				if (!(primer == '7' && segun == '8' && tercer == '9'))
					write(1, ", ", 2);
				tercer++;
			}
			segun++;
		}
		primer++;
	}
}
