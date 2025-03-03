/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:12:09 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/11 16:04:08 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int	get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (check_base(base))
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -sign;
			i++;
		}
		while (get_base_index(str[i], base) != -1)
			result = result * ft_strlen(base) + get_base_index(str[i++], base);
	}
	else
		result = 0;
	return (result * sign);
}

/*int main(void)
{
    char str[] = "1A";
    char base[] = "0123456789ABCDEF";

    int result = ft_atoi_base(str, base);
    char buffer[50];
    int len = snprintf(buffer, 50, "Resultado: %d\n", result);
    write(1, buffer, len);

    return 0;
}*/