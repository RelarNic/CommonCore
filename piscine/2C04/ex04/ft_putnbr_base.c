/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:12:03 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/11 15:53:52 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] >= 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	char	c;

	if (check_base(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= ft_strlen(base))
		{
			ft_putnbr_base(nb / ft_strlen(base), base);
		}
		c = base[nb % ft_strlen(base)];
		write(1, &c, 1);
	}
}

/*int main(void)
{
    char base[] = "0123456789ABCDEF";
    int number = 255;

    ft_putnbr_base(number, base);
    write(1, "\n", 1); // Para agregar un salto de línea después de la salida

    return 0;
}*/
