/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:17:49 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/08 18:27:24 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, unsigned int len)
{
	size_t			find_len;
	unsigned int	i;

	i = 0;
	find_len = ft_strlen(to_find);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && (i + find_len) <= len)
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp(&str[i], to_find, find_len) == 0)
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
    const char *str = "Hello, world!";
    const char *to_find = "world";
    const char *empty_to_find = "";
    const char *not_in_str = "42";
    const char *null_str = NULL;

    // Caso normal
    printf("Caso normal: %s\n", ft_strnstr(str, to_find, 13));
    // Caso con cadena de búsqueda vacía
    printf("Cadena vacía: %s\n", ft_strnstr(str, empty_to_find, 13));
    // Caso donde la cadena no contiene la subcadena
    printf("No está en la cadena: %s\n", ft_strnstr(str, not_in_str, 13));
    // Caso con cadena original NULL
    printf("Cadena NULL: %s\n", ft_strnstr(null_str, "fake", 3));

    return 0;
}
*/
