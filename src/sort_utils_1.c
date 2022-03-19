/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:25:49 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/19 08:04:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
** PUSH ELEMENTS BACK FROM STACK B TO A, GUARANTEEING THAT THE STACK A
** REMAINS FULLY ORDERED.
*/

void	ft_push_back(t_data *data)
{
	while (data->b->size)
	{
		ft_calculate_best_movement(data);
		ft_move(data);
	}
}

/*
** ALIGN STACK A SO THAT IT STARTS WITH THE SMALLEST NUMBER
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
		data->ft[operate](data, A);
}
