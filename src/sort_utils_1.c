/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:25:49 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:19:06 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	FT_PUSH_AWAY
**	------------
**	DESCRIPTION
**	Pushes elements from stack A to B in a semi-ordered way, until stack A is 
**	at least five elements long and fully sorted.
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
*/

void	ft_push_away(t_data *data)
{
	int	movement_id;

	while (data->a->size > 5)
	{
		ft_find_coef(data);
		movement_id = ft_get_push_away_id(data);
		if (movement_id > -1)
			ft_rotate(data, movement_id, 1);
		else
			ft_push(data, B, 1);
	}
	ft_sort_five(data);
}

/*	FT_PUSH_AWAY
**	------------
**	DESCRIPTION
**	Pushes elements back from stack B to A, guaranteeing that the stack A 
**	remains sorted.
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
*/

void	ft_push_back(t_data *data)
{
	while (data->b->size)
	{
		ft_calculate_best_movement(data);
		ft_move(data);
	}
}

/*	FT_ALIGN
**	------------
**	DESCRIPTION
**	Align elements on stack A so that the element on top is in fact the lowest.
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
*/

void	ft_align(t_data *data)
{
	int		operate;
	t_list	*temp;
	size_t	start_i;
	size_t	i;

	if (ft_is_sorted(data->a->list, data->a->order))
		return ;
	i = 0;
	start_i = 0;
	temp = data->a->list;
	while (temp)
	{
		if (temp->number > ft_list_at(data->a, start_i))
			start_i = i;
		temp = temp->next;
		i++;
	}
	operate = (++start_i > data->a->size / 2);
	if (start_i > data->a->size - start_i)
		start_i = data->a->size - start_i;
	while (start_i--)
		data->ft[operate](data, A, 1);
}
