/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:18:19 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/10 18:17:17 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cambio_hexa(char c, char *hex)
{
	char	*array;

	array = "0123456789abcdef";
	hex[0] = '\\';
	hex[1] = array[(unsigned char)c / 16];
	hex[2] = array[(unsigned char)c % 16];
	hex[3] = '\0';
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex_rep[4];

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			cambio_hexa(str[i], hex_rep);
			ft_putstr(hex_rep);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

/*int main() {
	char str[] = "Hello\nWorld\t!";
	ft_putstr_non_printable(str);
	return (0);
}*/