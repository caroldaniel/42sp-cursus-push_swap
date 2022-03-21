/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:56:58 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 11:47:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	FT_SWAP
**	------------
**	DESCRIPTION
**	Execute swap movement on one or both stacks, printing the movement or not
**	when finished.
**	PARAMETERS
**	#1. The t_data struct;
**	#2. The id of the movement (A for only stack a, B for b and R for both);
**	#3. The boolean paramenter for printing instruction on STDOUT or not.
**	RETURN VALUES
**	-
*/

void	ft_swap(t_data *data, int id, int is_print)
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
	if (is_print)
		ft_print_movement(SWAP, id);
}

/*
**	FT_PUSH
**	------------
**	DESCRIPTION
**	Execute push movement on one of the stacks, printing the movement or not
**	when finished.
**	PARAMETERS
**	#1. The t_data struct;
**	#2. The id of the movement (A for stack a or B for stack b);
**	#3. The boolean paramenter for printing instruction on STDOUT or not.
**	RETURN VALUES
**	-
*/

void	ft_push(t_data *data, int id, int is_print)
{
	if (id == R)
		return ;
	ft_stack_push(data, id);
	if (is_print)
		ft_print_movement(PUSH, id);
}

/*
**	FT_ROTATE
**	------------
**	DESCRIPTION
**	Execute rotate movement on one or both stacks, printing the movement or not
**	when finished.
**	PARAMETERS
**	#1. The t_data struct;
**	#2. The id of the movement (A for only stack a, B for b and R for both);
**	#3. The boolean paramenter for printing instruction on STDOUT or not.
**	RETURN VALUES
**	-
*/

void	ft_rotate(t_data *data, int id, int is_print)
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
	if (is_print)
		ft_print_movement(ROTATE, id);
}

/*
**	FT_REVERSE_ROTATE
**	------------
**	DESCRIPTION
**	Execute reverse_rotate movement on one or both stacks, printing the movement
**	or not when finished.
**	PARAMETERS
**	#1. The t_data struct;
**	#2. The id of the movement (A for only stack a, B for b and R for both);
**	#3. The boolean paramenter for printing instruction on STDOUT or not.
**	RETURN VALUES
**	-
*/

void	ft_reverse_rotate(t_data *data, int id, int is_print)
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
	if (is_print)
		ft_print_movement(REVERSE_ROTATE, id);
}
