/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:44:02 by njulia-c          #+#    #+#             */
/*   Updated: 2025/02/17 12:46:28 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		count;
	int		*numbers;

	if (argc==1)
		print_error("", 1);
	
	count = check_digits(argc, argv);
	numbers = parse_numbers(argc, argv, count);
	if (count <= 1 || num_duplicate(numbers, count) == true)
	{
		free(numbers);
		if (count == 1)
			print_error("", 1);
			//en el caso de que solo haya uno, pues debee haber minimo dos
		print_error("Error", 1);
	}
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;
	
	i = 1;
	count = 0;
	while (i<argc)
	{
		j = 0;
		while (argv[i][j] != NULL)
			{
				if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '-')
					return(-1);
				if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j + 1] != '\0'))
					count++;
				//revisar que sigue estructura "15 20 1" "11"
				j++;
			}
		i++;
	}
	return (count);
}

int *parse_numbers(int argc, char ** argv, int	count)
{
	int	i;
	int	z;
	int	j;
	int *numbers;
	char **numbers_div;

	i=0;
	numbers = (int *)malloc(count * sizeof(int));
	if (!numbers)
		return(NULL);
	while(i<argc  + 1)
	{
		numbers_div = ft_split(argv[i], ' ');
		if (!numbers)
			print_error("", 1);
		range_rev(numbers_div, numbers);
		z = 0;
		while (numbers_div[z])
			numbers[j++] = ft_atoi(numbers_div[z++]);
		free_matrix(numbers_div);
		i++;	
	}
}

void	check_range(char **numbers_div, int *numbers)
{
	int	i;

	i = 0;
	while (numbers_div[0])
	{
		if (ft_atoll)
	}
}