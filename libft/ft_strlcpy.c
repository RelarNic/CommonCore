/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:18:17 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/07 12:57:42 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copied_chars;

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
