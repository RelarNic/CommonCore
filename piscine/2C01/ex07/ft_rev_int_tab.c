/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:36:36 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/01 10:36:40 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temporal;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temporal = tab[i];
		tab[i] = tab[j];
		tab[j] = temporal;
		i++;
		j--;
	}
}
