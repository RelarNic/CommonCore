/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:18:20 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/08 18:25:52 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_dest > ptr_src && ptr_src + n > ptr_dest)
	{
		ptr_dest += n;
		ptr_src += n;
		while (n-- > 0)
			*--ptr_dest = *--ptr_src;
	}
	else
	{
		while (n-- > 0)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
