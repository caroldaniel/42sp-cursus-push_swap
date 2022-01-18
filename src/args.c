/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:00:52 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 11:14:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*get_arg_list(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*new;
	int		i;
	int		number;

	stack_a = NULL;
	new = NULL;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		new = stack_new(number);
		ft_stack_add_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}
