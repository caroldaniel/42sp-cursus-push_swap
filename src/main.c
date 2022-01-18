/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:53:24 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 15:22:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		error("Wrong usage. Use:\n\t./push_swap <number> [ <number> ... ]\n", 1);
	if (!check_args(argv))
		error("Error\n", 2);
	stack_a = get_arg_list(argc, argv);
	if (has_repeated_args(stack_a))
		error("Error\n", 2);
	stack_b = NULL;
	size_t size = ft_stack_len(stack_a);
	printf("%ld elements to sort\n", size);
	print_stack("Stack A", stack_a);
	print_stack("Stack B", stack_b);
	swap(&stack_a);
	printf("\n");
	print_stack("Stack A", stack_a);
	print_stack("Stack B", stack_b);
	push(&stack_a, &stack_b);
	printf("\n");
	print_stack("Stack A", stack_a);
	print_stack("Stack B", stack_b);
	push(&stack_a, &stack_b);
	printf("\n");
	print_stack("Stack A", stack_a);
	print_stack("Stack B", stack_b);
	rotate(&stack_a);
	printf("\n");
	print_stack("Stack A", stack_a);
	print_stack("Stack B", stack_b);
	reverse_rotate(&stack_a);
	printf("\n");
	print_stack("Stack A", stack_a);
	print_stack("Stack B", stack_b);
	return (0);
}
