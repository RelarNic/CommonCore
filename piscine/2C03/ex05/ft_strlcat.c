/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:55:08 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/04 13:42:40 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	total_len;
	unsigned int	copied_chars;

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
