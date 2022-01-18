/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:49:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 15:14:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CREATE NEW ITEM FOR STACK
*/
t_stack	*stack_new(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

/*
** FIND LAST ELEMENT ON STACK
*/
t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*
** ADD ITEM AFTER LAST ELEMENT OF STACK
*/
void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		temp = ft_stack_last(*stack);
		temp->next = new;
	}
}

/*
** ADD ITEM BEFORE FIRST ELEMENT OF STACK
*/
void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*elem;

	if (*stack == NULL)
		*stack = new;
	else
	{
		elem = new;
		elem->next = *stack;
		*stack = elem;
	}
}
