/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:47:51 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/11 12:29:11 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	size_calc(int size, char **strs, char *sep)
{
	int	i;
	int	final_size;
	int	sep_size;

	i = 0;
	final_size = 0;
	sep_size = ft_strlen(sep);
	while (size - i > 0)
	{
		final_size += ft_strlen(strs[i]);
		if (size > i + 1)
		{
			final_size += sep_size;
		}
		i++;
	}
	final_size += 1;
	return (final_size);
}

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		long_final;
	int		count;
	char	*empt;

	if (size == 0)
	{
		empt = malloc((1) * sizeof(char));
		if (empt == NULL)
			return (NULL);
		empt[0] = '\0';
		return (empt);
	}
	count = 0;
	long_final = size_calc(size, strs, sep);
	dest = malloc((long_final) * sizeof(char));
	dest[0] = '\0';
	while (size > count)
	{
		ft_strcat(dest, strs[count]);
		if (size > count + 1)
			ft_strcat(dest, sep);
		count++;
	}
	return (dest);
}

/*int main() {
    char *strs[] = {"Hola", "me/n", "lla1mo", "Nic'o"};
    char *sep = " ";
    int size = 4;
    char *result = ft_strjoin(size, strs, sep);
    if (result != NULL) {
        printf("Joined string: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed\n");
    }
    return 0;
}*/