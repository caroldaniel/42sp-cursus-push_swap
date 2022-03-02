/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:46:56 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/02 15:05:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

/*
** SWAP FIRST TWO ELEMENTS OF LINKED LIST
*/

void	ft_stack_swap(t_stack **stack)
{
	t_list	*a;
	t_list	*b;

	a = (*stack)->list;
	b = a->next;
	if (!b)
		return ;
	a->next = b->next;
	b->next = a;
	(*stack)->list = b;
}

/*
** PUSH FIRST ELEMENT OF LIST TO TOP OF ANOTHER
*/

void	ft_stack_push(t_data *data, int id)
{
	t_stack	*from;
	t_stack	*to;
	t_list	*moved;

	if (id == A)
	{
		from = data->b;
		to = data->a;
	}
	else if (id == B)
	{
		from = data->a;
		to = data->b;
	}
	moved = from->list;
	from->list = from->list->next;
	moved->next = NULL;
	ft_list_add_front(&(to->list), moved);
	ft_stack_range(&from);
	ft_stack_range(&to);
}

/*
** ROTATE LIST
*/

void	ft_stack_rotate(t_stack **stack)
{
	t_list	*moved;
	t_list	**list;

	moved = (*stack)->list;
	(*stack)->list = (*stack)->list->next;
	moved->next = NULL;
	list = &(*stack)->list;
	ft_list_add_back(list, moved);
}

/*
** REVERSE ROTATE LIST
*/

void	ft_stack_reverse_rotate(t_stack **stack)
{
	t_list	*moved;
	t_list	*temp;
	size_t	list_size;
	size_t	i;

	list_size = ft_list_len((*stack)->list);
	moved = ft_list_last((*stack)->list);
	moved->next = (*stack)->list;
	(*stack)->list = moved;
	temp = (*stack)->list;
	i = 0;
	while (++i < list_size)
		temp = temp->next;
	temp->next = NULL;
}
