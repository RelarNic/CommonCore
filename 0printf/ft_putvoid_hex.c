/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:06:04 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/23 12:01:15 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid_hex(unsigned long p)
{
	int				count;
	unsigned long	ptr_val;
	void			*p_void;

	count = 0;
	p_void = (void *)p;
	if (p_void == NULL)
	{
		count += print_str("(nil)");
		return (count);
	}
	count += write(1, "0x", 2);
	ptr_val = (unsigned long)p;
	count += ft_putnbr_base(ptr_val, "0123456789abcdef");
	return (count);
}
