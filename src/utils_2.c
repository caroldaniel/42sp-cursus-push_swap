/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:33:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:09:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_position_by_max(t_stack *stack, size_t max_i);

/*	FT_GET_PUSH_AWAY_ID
**	------------
**	DESCRIPTION
**	Calculates in which stacks we should apply the specif movements on 
**	push_away function (A for only A, B for only B and R for both). 
**	PARAMETERS
**	#1. The t_data struct with both stacks within it.
**	RETURN VALUES
**	0 for A, 1 for B or 2 for R.
*/

int	ft_get_push_away_id(t_data *data)
{
	int	is_a;
	int	is_b;

	is_a = !(ft_count_lowers(data->a) > data->a->size * data->coef[A]);
	is_b = ft_count_lowers(data->b) > data->b->size * data->coef[B];
	if (is_a && is_b)
		return (R);
	else if (is_a)
		return (A);
	else if (is_b)
		return (B);
	return (-1);
}

/*	FT_GET_SORT_FIVE_ROTATE_ID
**	------------
**	DESCRIPTION
**	Calculates in which stacks we should apply the rotation movement on 
**	sort_five function (A for only A, B for only B and R for both). 
**	PARAMETERS
**	#1. The t_data struct with both stacks within it.
**	RETURN VALUES
**	0 for A, 2 for R or -1 for error.
*/

int	ft_get_sort_five_rotate_id(t_data *data)
{
	int	number;
	int	last;
	int	is_a;
	int	is_b;

	number = data->a->list->number;
	last = ft_list_last(data->a->list)->number;
	is_a = number > last;
	if (data->b->size < 2)
	{
		if (is_a)
			return (A);
		else
			return (-1);
	}
	number = data->b->list->number;
	last = ft_list_last(data->b->list)->number;
	is_b = number < last;
	if (is_a && is_b)
		return (R);
	else if (is_a)
		return (A);
	return (-1);
}

/*	FT_GET_SORT_FIVE_SWAP_ID
**	------------
**	DESCRIPTION
**	Calculates in which stacks we should apply the swap movement on 
**	sort_five function (A for only A, B for only B and R for both). 
**	PARAMETERS
**	#1. The t_data struct with both stacks within it.
**	RETURN VALUES
**	0 for A, 2 for R or -1 for error.
*/

int	ft_get_sort_five_swap_id(t_data *data)
{
	int	number;
	int	next;
	int	is_a;
	int	is_b;

	number = data->a->list->number;
	next = data->a->list->next->number;
	is_a = number > next;
	if (data->b->size < 2)
	{
		if (is_a)
			return (A);
		else
			return (-1);
	}
	number = data->b->list->number;
	next = data->b->list->next->number;
	is_b = number < next;
	if (is_a && is_b)
		return (R);
	else if (is_a)
		return (A);
	return (-1);
}

/*	FT_GET_POSITION
**	------------
**	DESCRIPTION
**	Calculates in which position on stack A the given number will be put on the
**	push_back function. 
**	PARAMETERS
**	#1. The t_stack struct;
**	#2. The number to place.
**	RETURN VALUES
**	The integer correspondent to the position of the placement. Negative values 
**	are used to indicate reverse_rotation.
*/

int	ft_get_position(t_stack *stack, int nb)
{
	size_t	i;
	size_t	max_i;
	t_list	*curr;
	t_list	*last;

	i = 0;
	max_i = 0;
	curr = stack->list;
	last = ft_list_last(stack->list);
	while (curr)
	{
		if (nb < curr->number && nb > last->number)
		{
			if (i <= stack->size - i)
				return (i);
			return (-(stack->size - i));
		}
		if (curr->number > ft_list_at(stack, max_i))
			max_i = i;
		last = curr;
		curr = curr->next;
		i++;
	}
	return (ft_position_by_max(stack, ++max_i));
}

static size_t	ft_position_by_max(t_stack *stack, size_t max_i)
{
	if (max_i > stack->size / 2)
		return (-(stack->size - max_i));
	return (max_i);
}
