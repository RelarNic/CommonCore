/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:06:04 by njulia-c          #+#    #+#             */
/*   Updated: 2025/01/03 20:20:17 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base_extra(unsigned long long nb, const char *base)
{
	char				c;
	int					count;
	unsigned long long	base_len;

	count = 0;
	base_len = (unsigned long long)ft_strlen(base);
	if (nb >= base_len)
		count += ft_putnbr_base(nb / base_len, base);
	c = base[nb % base_len];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putvoid_hex(void *p)
{
	int					count;
	unsigned long long	ptr_val;

	count = 0;
	ptr_val = (unsigned long long)p;
	if (p == NULL)
	{
		count += print_str("(nil)");
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_putnbr_base_extra(ptr_val, "0123456789abcdef");
	return (count);
}
