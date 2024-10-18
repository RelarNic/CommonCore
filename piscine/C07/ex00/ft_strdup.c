/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:47:08 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/05 12:33:30 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*temp;
	int		len;

	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	temp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

/*int	main(void)
{
	char	*str;
	char	*duplicated_str;

	str = "hola";
	duplicated_str = ft_strdup(str);
	if (duplicated_str == NULL)
	{
		printf("Error al duplicar la cadena\n");
		return (1);
	}

	printf("Cadena original: %s\n", str);
	printf("Cadena duplicada: %s\n", duplicated_str);

	free(duplicated_str);
	return (0);
}*/