/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:42:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:14:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	FT_COUNT_LOWERS
**	------------
**	DESCRIPTION
**	Counts how many numbers are lower then the one on top of stack.
**	PARAMETERS
**	#1. The t_stack struct.
**	RETURN VALUES
**	An unsigned int correstpondent to the count.
*/

size_t	ft_count_lowers(t_stack *stack)
{
	t_list	*aux;
	int		first;
	size_t	lowers;

	if (!stack->list)
		return (0);
	aux = stack->list;
	first = aux->number;
	lowers = 0;
	while (aux)
	{
		if (first < aux->number)
			lowers++;
		aux = aux->next;
	}
	return (lowers);
}

/*	FT_GET_SORT_FIVE_SWAP_ID
**	------------
**	DESCRIPTION
**	Calculates how many operations are taken to move a number to the position
**	given. 
**	PARAMETERS
**	#1. The position parameter.
**	RETURN VALUES
**	An unsigned int correstpondent to the count.
*/

size_t	ft_count_moves(int *position)
{
	if (position[A] * position[B] > 0)
	{
		if (position[A] > 0)
		{
			if (position[A] > position[B])
				return (position[A]);
			return (position[B]);
		}
		else if (position[A] < position[B])
			return (-position[A]);
		else
			return (-position[B]);
	}
	else
		return (ft_abs(position[A]) + ft_abs(position[B]));
}

/*	FT_FIND_COEF
**	------------
**	DESCRIPTION
**	Populated the coef list with the correspondent static values below.
**	PARAMETERS
**	#1. The t_data struct with the stack A defined. 
**	RETURN VALUES
**	-
*/

void	ft_find_coef(t_data	*data)
{
	if (data->a->size >= 50)
	{
		data->coef[A] = 0.67;
		data->coef[B] = 0.2;
	}
	else
	{
		data->coef[A] = 0.33;
		data->coef[B] = 0.5;
	}
}

/*	FT_PRINT_MOVEMENT
**	------------
**	DESCRIPTION
**	Prints the movement instruction on screen.
**	PARAMETERS
**	#1. The operation indicator;
**	#2. The id of the stack(s) moved. 
**	RETURN VALUES
**	-
*/

void	ft_print_movement(int operation, int stack_id)
{
	if (operation == SWAP)
		write(1, "s", 1);
	else if (operation == PUSH)
		write(1, "p", 1);
	else if (operation == ROTATE)
		write(1, "r", 1);
	else if (operation == REVERSE_ROTATE)
		write(1, "rr", 2);
	if (stack_id == A)
		write(1, "a\n", 2);
	else if (stack_id == B)
		write(1, "b\n", 2);
	else if (stack_id == R && operation != SWAP)
		write(1, "r\n", 2);
	else
		write(1, "s\n", 2);
}
