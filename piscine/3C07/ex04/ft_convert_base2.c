/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:50:05 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/13 13:55:53 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	get_base_index(char c, char *base);
int	ft_atoi_base(char *nbr, char *base);

int	new_size_expected(int nbr, int len)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		size = 1;
	}
	while (nbr)
	{
		nbr /= len;
		size++;
	}
	return (size);
}

char	*to_base(int nb, char *base_to)
{
	char	*c;
	int		i;
	int		min_int_flag;

	i = new_size_expected(nb, ft_strlen(base_to));
	c = malloc((new_size_expected(nb, ft_strlen(base_to)) + 1) * sizeof(char));
	if (!c)
		return (NULL);
	c[i] = '\0';
	if (nb == 0)
		c[0] = base_to[0];
	if (nb < 0)
	{
		c[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		c[--i] = base_to[nb % ft_strlen(base_to)];
		nb /= ft_strlen(base_to);
	}
	return (c);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	temp;

	if (check_base(base_from) && check_base(base_to))
	{
		temp = ft_atoi_base(nbr, base_from);
		return (to_base(temp, base_to));
	}
	else
		return (NULL);
}

/*int main(void)
{
    char nbr[] = "0";
    char base_from[] = "0123456789ABCDEF";
    char base_to[] = "0123456789";

    char *result = ft_convert_base(nbr, base_from, base_to);
    if (result)
    {
        printf("Resultado: %s\n", result);
        free(result);
    }
    else
    {
        printf("Error en la conversión.\n");
    }

    return 0;
}*/