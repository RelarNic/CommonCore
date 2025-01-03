/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:17:14 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/15 17:19:19 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	palabras_count(const char *str, char c)
{
	int	i;
	int	palabras;
	int	en_palabra;

	i = 0;
	palabras = 0;
	en_palabra = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] == c))
		{
			if (!en_palabra)
			{
				palabras++;
				en_palabra = 1;
			}
		}
		else
			en_palabra = 0;
		i++;
	}
	return (palabras);
}

char	*ft_create_word(const char *inicio, const char *fin)
{
	char	*dest;
	int		len;
	int		i;

	len = fin - inicio;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = inicio[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_split(char **palabras)
{
	int	i;

	if (!palabras)
		return ;
	i = 0;
	while (palabras[i])
	{
		free(palabras[i]);
		i++;
	}
	free(palabras);
}

char	**ft_create_sentence(char **palabras, char const *str, char c)
{
	int			i;
	int			j;
	const char	*start;

	i = 0;
	j = 0;
	start = NULL;
	while (str[i])
	{
		if (!(str[i] == c) && !(start))
			start = &str[i];
		else if (str[i] == c && start)
		{
			palabras[j] = ft_create_word(start, &str[i]);
			if (!palabras[j])
				return (NULL);
			start = NULL;
			j++;
		}
		i++;
	}
	if (start)
		palabras[j++] = ft_create_word(start, &str[i]);
	return (palabras);
}

char	**ft_split(char const *str, char c)
{
	char	**palabras;
	int		num_palabras;

	num_palabras = palabras_count(str, c);
	palabras = (char **)malloc((num_palabras + 1) * sizeof(char *));
	if (!palabras)
		return (NULL);
	if (!ft_create_sentence(palabras, (char *)str, c))
	{
		free_split(palabras);
		return (NULL);
	}
	palabras[num_palabras] = NULL;
	return (palabras);
}
