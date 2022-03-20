/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/20 18:59:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_data	*ft_init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_end_program(data, 3);
	if (argc - 1 == 1)
		data->args = ft_split(argv[1], ' ');
	else
		data->args = ft_args_copy(&argv[1], argc - 1);
	ft_init_stacks(data);
	if (!ft_check_args(data))
		ft_end_program(data, 2);
	data->pos = (int *)malloc(sizeof(int) * 2);
	data->tmp = (int *)malloc(sizeof(int) * 2);
	data->ft[ROTATE] = ft_rotate;
	data->ft[REVERSE_ROTATE] = ft_reverse_rotate;
	if (!data->pos || !data->tmp)
		ft_end_program(data, 4);
	return (data);
}

void	ft_init_stacks(t_data *data)
{
	data->a = (t_stack *)malloc(sizeof(t_stack));
	data->b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->a || !data->b)
		ft_end_program(data, 4);
	ft_get_stack_list(data);
	if (!data->a->list)
		ft_end_program(data, 4);
	ft_stack_range(&data->a);
	ft_stack_range(&data->b);
	data->a->order = ASCENDING;
	data->b->order = DESCENDING;
}
