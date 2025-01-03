/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:36:51 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/07 11:14:40 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;
	size_t	lenn;

	i = 0;
	lenn = ft_strlen(s);
	if (s == NULL || f == NULL)
		return (NULL);
	result = malloc((lenn + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[lenn] = '\0';
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
