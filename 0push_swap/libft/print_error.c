/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:37:37 by njulia-c          #+#    #+#             */
/*   Updated: 2025/02/17 11:42:53 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

void	print_error(char *txt, bool exit_statement)
{
	write(2, txt, ft_strlen(txt));
	if (exit_statement == true)
		exit(EXIT_FAILURE);
}
