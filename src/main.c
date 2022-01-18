/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:53:24 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 11:20:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 1)
		error("Wrong number of arguments\n", 1);
	if (!check_args(argv))
		error("Arguments not numeric\n", 2);
	stack_a = get_arg_list(argc, argv);
	while (stack_a)
	{
		printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	return (0);
}
