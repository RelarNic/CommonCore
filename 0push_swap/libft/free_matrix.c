/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:40:27 by njulia-c          #+#    #+#             */
/*   Updated: 2025/02/17 12:43:53 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

void	free_matrix(char	**matrix)
{
	size_t	i;

	i = 0;
	if (matrix)
	{
		while (matrix && matrix[i])
		{
			if (matrix[i] != NULL)
			{
				free(matrix[i]);
				matrix[i] = NULL;
			}
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}