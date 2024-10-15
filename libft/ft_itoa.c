/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:40:19 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/07 11:13:59 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int nb)
{
	int	len;

	len = (nb <= 0);
	while (nb && ++len)
		nb /= 10;
	return (len);
}

char	*ft_itoa(int nb)
{
	char			*c;
	int				len;

	len = get_len(nb);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!(c))
		return (NULL);
	c[len] = '\0';
	if (nb == -2147483648)
		ft_strlcpy(c, "-2147483648", len + 1);
	if (nb < 0 && nb != -2147483648)
	{
		c[0] = '-';
		nb = -nb;
	}
	while (len != 0 && nb != -2147483648)
	{
		if (c[0] == '-' && len == 1)
			return (c);
		c[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (c);
}
