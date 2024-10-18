/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:51:48 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/02 13:53:40 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n--)
	{
		if (*s1 != *s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (0);
}
