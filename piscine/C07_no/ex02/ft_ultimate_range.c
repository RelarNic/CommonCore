/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:47:31 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/05 14:21:42 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*temp;
	int	len;
	int	i;

	len = max - min;
	if (len <= 0)
	{
		return (0);
	}
	temp = malloc((len) * sizeof(int));
	i = 0;
	if (temp == NULL)
	{
		return (-1);
	}
	while (i < len)
	{
		temp[i] = min + i;
		i++;
	}
	*range = temp;
	return (len);
}

/*int	main(void)
{
	int	min;
	int	max;s
	int	solucion;
	int	i;
	int	*range;

	min = 2;
	max = 8;
	i = 0;
	solucion = ft_ultimate_range(&range, min, max);
	if (solucion == 0)
	{
		printf("Error al crear la lista\n");
		return (1);
	}
	while (i < solucion)
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("long Array creado: %d", solucion);
	printf("\n");
	free(range);
	return (0);
}*/