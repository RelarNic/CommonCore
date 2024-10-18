/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:19:01 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/03 11:04:34 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = dest;
	while (i < n && *src != '\0')
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest++ = '\0';
		i++;
	}
	return (temp);
}
