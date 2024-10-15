/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:17:51 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/08 17:47:13 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*temp;

	temp = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		long_final;
	char	*empt;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return ((char *)s1);
	long_final = ft_strlen(s1) + ft_strlen(s2);
	if (long_final == 0)
	{
		empt = malloc((1) * sizeof(char));
		if (empt == NULL)
			return (NULL);
		empt[0] = '\0';
		return (empt);
	}
	dest = malloc((long_final + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
