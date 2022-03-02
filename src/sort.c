/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:48:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/02 15:20:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>	

void	ft_sort_stack(t_data *data)
{
	ft_print_stack("STACK A", data->a->list);
	ft_print_stack("STACK B", data->b->list);
	ft_push_away(data);
	ft_print_stack("STACK A", data->a->list);
	ft_print_stack("STACK B", data->b->list);
}

/*
** PUSH ELEMENTS FROM STACK A TO B IN A SEMI-ORDERED WAY, UNTIL STACK A IS 
** AT LEAST FIVE ELEMENTS LONG AND FULLY SORTED.
*/

void	ft_push_away(t_data *data)
{
	int	movement_id;

	while (data->a->size > 5)
	{
		ft_find_coef(data);
		movement_id = ft_get_push_away_id(data);
		if (movement_id > -1)
			ft_rotate(data, movement_id);
		else
			ft_push(data, B);
	}
	ft_sort_five(data);
}

/*
** PUSH ELEMENTS FROM STACK A TO B IN A SEMI-ORDERED WAY, UNTIL STACK A IS 
** AT LEAST FIVE ELEMENTS LONG AND FULLY SORTED.
*/

void	ft_sort_five(t_data *data)
{
	int	rotate_id;
	int	swap_id;

	while (!ft_is_sorted(data->a->list, data->a->order) || data->b->size)
	{
		rotate_id = ft_get_sort_five_rotate_id(data);
		swap_id = ft_get_sort_five_swap_id(data);
		if (rotate_id > -1)
			ft_rotate(data, rotate_id);
		else if (swap_id > -1)
			ft_swap(data, swap_id);
		else if (!ft_is_sorted(data->a->list, data->a->order))
			ft_push(data, B);
		else if (data->a->size + data->b->size < 6)
			ft_push(data, A);
		else
			break ;
	}
}
