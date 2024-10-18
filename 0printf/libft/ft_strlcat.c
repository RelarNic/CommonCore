/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:18:15 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/07 12:59:18 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	copied_chars;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	copied_chars = 0;
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while (src[copied_chars] && (copied_chars + dest_len < size - 1))
	{
		dest[dest_len + copied_chars] = src[copied_chars];
		copied_chars++;
	}
	dest[dest_len + copied_chars] = '\0';
	return (total_len);
}
