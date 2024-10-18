/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:54:39 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/02 13:54:41 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*temp_str;
	char	*temp_to_find;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str)
	{
		temp_str = str;
		temp_to_find = to_find;
		while (*temp_to_find && *temp_str == *temp_to_find)
		{
			temp_str++;
			temp_to_find++;
		}
		if (*temp_to_find == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
