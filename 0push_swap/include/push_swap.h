/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:17:57 by njulia-c          #+#    #+#             */
/*   Updated: 2025/02/17 11:29:11 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct d_node
{
	int				data;
	struct d_node	*prev;
	struct d_node	*next;
}					t_node;

typedef struct d_list
{
	d_node			*head;
	d_node			*tail;
	int				size;
}					t_list;

#endif