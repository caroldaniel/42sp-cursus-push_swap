/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:00:52 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/19 11:40:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"		

/*
** CHECK IF ARGUMENTS PASSED ARE VALID - NUMERIC AND NON REPEATED
*/

int	ft_check_args(t_data *data, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isnumeric(args[i][j]))
				return (0);
			j++;
		}
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi_mod(data, args[i]) == ft_atoi_mod(data, args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** EXTRACT ARGUMENT LIST TO LINKED LIST OF INT
*/

t_list	*ft_get_stack_list(t_data *data, char **args)
{
	t_list	*list;
	t_list	*new;
	int		i;

	list = NULL;
	i = 0;
	while (args[i])
	{
		new = ft_list_new(ft_atoi_mod(data, args[i]));
		if (!new && list)
		{
			ft_clear_list(&list);
			break ;
		}
		ft_list_add_back(&list, new);
		i++;
	}
	return (list);
}

/*
** GET SIZE AND RANGE OF STACK
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
