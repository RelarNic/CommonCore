/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:18:04 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/10 18:24:48 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	copied_chars;

	src_len = ft_strlen(src);
	copied_chars = 0;
	if (size > 0)
	{
		while (src[copied_chars] && (copied_chars < size - 1))
		{
			dest[copied_chars] = src[copied_chars];
			copied_chars++;
		}
		dest[copied_chars] = '\0';
	}
	return (src_len);
}
