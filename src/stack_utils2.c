/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:44:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 15:12:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** GET STACK LENGTH
*/

size_t	ft_stack_len(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	print_stack(char *name, t_stack *stack)
{
	size_t	stack_len;
	size_t	i;
	char	*nb;
	
	stack_len = ft_stack_len(stack);
	i = 0;
	nb = NULL;
	ft_putstr_fd(name, 1);
	ft_putstr_fd(": ", 1);
	if (stack_len == 0)
		ft_putstr_fd("[ EMPTY ]\n", 1);
	while (i < stack_len)
	{
		if (i == 0)
			ft_putstr_fd("[ ", 1);
		nb = ft_itoa(stack->number);
		ft_putstr_fd(nb, 1);
		i++;
		if (i == stack_len)
			ft_putstr_fd(" ]\n", 1);
		else
			ft_putstr_fd(", ", 1);
		stack = stack->next;
	}
}

int	has_repeated_args(t_stack *stack)
{
	t_stack	*checker;
	
	checker = NULL;
	while (stack)
	{
		checker = stack->next;
		while(checker)
		{
			if (stack->number == checker->number)
				return (1);
			checker = checker->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	is_number_in_stack(int number, t_stack *stack)
{
	while (stack)
	{
		if (stack->number == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}
