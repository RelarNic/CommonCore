/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:51:29 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/23 11:22:57 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
		write(1, &s[count++], 1);
	return (count);
}
