/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:21:46 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/07 10:20:07 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	separa(char a, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_adapted(char const *s, int start, int len)
{
	char	*dest;
	char	*temp;
	int		i;

	if (s == NULL)
		return (NULL);
	dest = malloc((len + 1) * sizeof(char));
	i = 0;
	if (dest == NULL)
		return (NULL);
	temp = dest;
	while (len > 0 && s[start] != '\0')
	{
		dest[i++] = s[start++];
		len--;
	}
	dest[i] = '\0';
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		longitud;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	longitud = ft_strlen(s1) - 1;
	i = 0;
	while (separa(s1[i], set) && s1[i] != '\0')
		i++;
	while (separa(s1[longitud], set) && longitud >= i)
		longitud--;
	dest = ft_substr(s1, i, longitud - i + 1);
	return (dest);
}
