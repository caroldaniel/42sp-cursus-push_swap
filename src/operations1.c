/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:46:56 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 15:25:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *a;
	t_stack *b;
	
	a = *stack;
	b = (*stack)->next;
	if (!b)
		return ;
	a->next = b->next;
	b->next = a;
	*stack = b;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack *moved;
	
	moved = *from;
	*from = (*from)->next;
	moved->next = NULL;
	ft_stack_add_front(to, moved);
}

void	rotate(t_stack **stack)
{
	t_stack *moved;

	moved = *stack;
	*stack = (*stack)->next;
	moved->next = NULL;
	ft_stack_add_back(stack, moved);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *moved;
	t_stack *temp;
	size_t	stack_size;
	size_t	i;
	
	stack_size = ft_stack_len(*stack);
	moved = ft_stack_last(*stack);
	moved->next = *stack;
	*stack = moved;
	temp = *stack;
	i = 0;
	while (++i < stack_size)
		temp = temp->next;
	temp->next = NULL;
}
