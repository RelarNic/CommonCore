/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:49:57 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/12 20:01:55 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	separa(char a, char *charset)
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

int	palabras_count(char *str, char *charset)
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
		if (!separa(str[i], charset))
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

char	*ft_create_word(char *inicio, char *fin)
{
	char	*dest;
	int		len;
	int		i;

	len = fin - inicio;
	dest = malloc((len + 1) * sizeof(char));
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (len > 0)
	{
		dest[i] = inicio[i];
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_create_sentence(char **palabras, char *str, char *charset)
{
	int		i;
	int		j;
	char	*start;

	i = 0;
	j = 0;
	start = NULL;
	while (str[i])
	{
		if (!(separa(str[i], charset)))
		{
			if (!(start))
				start = &str[i];
		}
		else if (start)
		{
			palabras[j] = ft_create_word(start, &str[i]);
			start = NULL;
			j++;
		}
		i++;
	}
	if (start)
		palabras[j] = ft_create_word(start, &str[i]);
	return (palabras);
}

char	**ft_split(char *str, char *charset)
{
	char	**palabras;
	int		num_palabras;

	num_palabras = palabras_count(str, charset);
	palabras = (char **)malloc((num_palabras + 1) * sizeof(char *));
	if (!palabras)
		return (NULL);
	ft_create_sentence(palabras, str, charset);
	palabras[num_palabras] = NULL;
	return (palabras);
}

/*int main() {
    char str[] = "Hola, mundo! Bienvenidos a la programación en C";
    char charset[] = " ";
    char **result = ft_split(str, charset);
    int i = 0;

    if (result != NULL) {
        while (result[i] != NULL) {
            printf("Palabra %d: %s\n", i + 1, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    } else {
        printf("Error en la división de la cadena.\n");
    }

    return 0;
}*/