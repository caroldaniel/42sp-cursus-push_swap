/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:00:52 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 11:47:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"		

/*	FT_CHECK_ARGS
**	------------
**	DESCRIPTION
**	Checks for repeated values among argument list.
**	PARAMETERS
**	#1. The t_data struct with arguments allocated within it.
**	RETURN VALUES
**	Returns 1 for correct list os arguments, and 0 for any mistakes found in it.
*/

int	ft_check_args(t_data *data)
{
	t_list	*tmp;
	t_list	*iterator;

	tmp = data->a->list;
	while (tmp)
	{
		iterator = tmp->next;
		while (iterator)
		{
			if (tmp->number == iterator->number)
				return (0);
			iterator = iterator->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

/*	FT_GET_STACK_LIST
**	------------
**	DESCRIPTION
**	Converts arguments from given parameters into stack A's linked list initial
**	state.
**	PARAMETERS
**	#1. The t_data struct with arguments allocated within it.
**	RETURN VALUES
**	-
*/

void	ft_get_stack_list(t_data *data)
{
	t_list	*new;
	int		i;

	data->a->list = NULL;
	i = 0;
	while (data->args[i])
	{
		new = ft_list_new(ft_atoi_mod(data, i));
		if (!new && data->a->list)
		{
			ft_clear_list(&data->a->list);
			break ;
		}
		ft_list_add_back(&data->a->list, new);
		i++;
	}
}

/*	FT_STACK_RANGE
**	------------
**	DESCRIPTION
**	Gets range of numbers contained in stack.
**	PARAMETERS
**	#1. The t_stack struct with list allocated within it.
**	RETURN VALUES
**	-
*/

void	ft_stack_range(t_stack **stack)
{
	t_list	*list;
	int		min;
	int		max;

	list = (*stack)->list;
	(*stack)->size = 0;
	if (list)
	{
		min = (*stack)->list->number;
		max = (*stack)->list->number;
		while (list)
		{
			(*stack)->size++;
			if (list->number > max)
				max = list->number;
			if (list->number < min)
				min = list->number;
			list = list->next;
		}
		(*stack)->range = (size_t)(max - min);
	}
	else
		(*stack)->range = 0;
}
