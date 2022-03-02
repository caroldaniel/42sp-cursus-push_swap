/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:56:58 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/02 14:55:00 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
/*
** SWAP FIRST TWO ELEMENTS OF STACK (ra, rb, rr)
*/

void	ft_swap(t_data *data, int id)
{
	if (id == A)
		ft_stack_swap(&data->a);
	else if (id == B)
		ft_stack_swap(&data->b);
	else if (id == R)
	{
		ft_stack_swap(&data->a);
		ft_stack_swap(&data->b);
	}
	ft_print_movement(SWAP, id);
}

/*
** PUSH FIRST ELEMENT OF STACK TO THE TOP OF THE OTHER (pa, pb)
*/

void	ft_push(t_data *data, int id)
{
	if (id == R)
		return ;
	ft_stack_push(data, id);
	ft_print_movement(PUSH, id);
}

/*
** ROTATE STACKS (ra, rb, rr)
*/

void	ft_rotate(t_data *data, int id)
{
	if (id == A)
		ft_stack_rotate(&data->a);
	else if (id == B)
		ft_stack_rotate(&data->b);
	else if (id == R)
	{
		ft_stack_rotate(&data->a);
		ft_stack_rotate(&data->b);
	}
	ft_print_movement(ROTATE, id);
}

/*
** REVERSE ROTATE STACKS (rra, rrb, rrr)
*/

void	ft_reverse_rotate(t_data *data, int id)
{
	if (id == A)
		ft_stack_reverse_rotate(&data->a);
	else if (id == B)
		ft_stack_reverse_rotate(&data->b);
	else if (id == R)
	{
		ft_stack_reverse_rotate(&data->a);
		ft_stack_reverse_rotate(&data->b);
	}
	ft_print_movement(REVERSE_ROTATE, id);
}