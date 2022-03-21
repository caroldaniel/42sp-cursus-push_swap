/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:29:27 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:23:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	FT_SORT_FIVE
**	------------
**	DESCRIPTION
**	Sorts a list of a maximum number of five elements.
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
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
			ft_rotate(data, rotate_id, 1);
		else if (swap_id > -1)
			ft_swap(data, swap_id, 1);
		else if (!ft_is_sorted(data->a->list, data->a->order))
			ft_push(data, B, 1);
		else if (data->a->size + data->b->size < 6)
			ft_push(data, A, 1);
		else
			break ;
	}
}

/*	FT_CALCULATE_BEST_MOVEMENT
**	------------
**	DESCRIPTION
**	Calculates which movement will have the minimum number of instructions on
**	the push_back funciton.
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
*/

void	ft_calculate_best_movement(t_data *data)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = data->b->size;
	data->pos[A] = ft_get_position(data->a, ft_list_at(data->b, i));
	data->pos[B] = i++;
	while (i < data->b->size / 2 && i < ft_count_moves(data->pos))
	{
		data->tmp[A] = ft_get_position(data->a, ft_list_at(data->b, i));
		data->tmp[B] = i;
		if (ft_count_moves(data->pos) > ft_count_moves(data->tmp))
			ft_memcpy(data->pos, data->tmp, sizeof(int) * 2);
		data->tmp[A] = ft_get_position(data->a, ft_list_at(data->b, n - i));
		data->tmp[B] = -i;
		if (ft_count_moves(data->pos) > ft_count_moves(data->tmp))
			ft_memcpy(data->pos, data->tmp, sizeof(int) * 2);
		i++;
	}
}

/*	FT_CALCULATE_BEST_MOVEMENT
**	------------
**	DESCRIPTION
**	Moves the stack accordingly to the best movement found. 
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
*/

void	ft_move(t_data *data)
{
	data->operate = data->pos[A] < 0;
	if (data->pos[A] > 0 && data->pos[B] > 0)
	{
		if (data->pos[A] > 0)
			data->counter = data->pos[data->pos[A] > data->pos[B]];
		else
			data->counter = data->pos[data->pos[A] < data->pos[B]];
				data->pos[A] -= data->counter;
		data->pos[B] -= data->counter;
		data->counter = ft_abs(data->counter);
		while (--data->counter >= 0)
			data->ft[data->operate](data, R, 1);
	}
	data->pos[A] = ft_abs(data->pos[A]);
	while (--data->pos[A] >= 0)
		data->ft[data->operate](data, A, 1);
	data->operate = data->pos[B] < 0;
	data->pos[B] = ft_abs(data->pos[B]);
	while (--data->pos[B] >= 0)
		data->ft[data->operate](data, B, 1);
	ft_push(data, A, 1);
}
