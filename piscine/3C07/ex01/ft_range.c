/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:47:20 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/05 13:47:17 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	*temp;
	int	len;
	int	i;

	len = max - min;
	if (len <= 0)
	{
		return (NULL);
	}
	dest = malloc((len) * sizeof(int));
	i = 0;
	if (dest == NULL)
	{
		return (NULL);
	}
	temp = dest;
	while (len > 0)
	{
		dest[i] = max - len;
		len--;
		i++;
	}
	return (temp);
}

/*int	main(void)
{
	int	min;
	int	max;
	int	*solucion;
	int	i;

	min = 2;
	max = 8;
	i = 0;
	solucion = ft_range(min,max);
	if (solucion == NULL)
	{
		printf("Error al crear la lista\n");
		return (1);
	}
	printf("Array creado: ");
	while (i < (max - min))
	{
		printf("%d ", solucion[i]);
		i++;
	}
	printf("\n");
	free(solucion);
	return (0);
}*/