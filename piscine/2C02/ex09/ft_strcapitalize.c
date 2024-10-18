/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:17:43 by njulia-c          #+#    #+#             */
/*   Updated: 2024/06/01 12:17:46 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	int	condicion;

	condicion = 0;
	if (c >= 'a')
	{
		if (c <= 'z')
		{
			condicion = 1;
		}
	}
	if (c >= 'A')
	{
		if (c <= 'Z')
		{
			condicion = 1;
		}
	}
	if (c >= '0')
	{
		if (c <= '9')
		{
			condicion = 1;
		}
	}
	return (condicion);
}

char	to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}

char	to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}

int	is_word_start(char prev, char current)
{
	int	condicion;

	condicion = 0;
	if (!is_alphanumeric(prev) && is_alphanumeric(current))
	{
		condicion = 1;
	}
	return (condicion);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		str[i] = to_uppercase(str[i]);
	}
	i++;
	while (str[i] != '\0')
	{
		if (is_word_start(str[i - 1], str[i]))
		{
			str[i] = to_uppercase(str[i]);
		}
		else
		{
			str[i] = to_lowercase(str[i]);
		}
		i++;
	}
	return (str);
}
