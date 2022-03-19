/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:53:24 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/18 13:49:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0)
		ft_end_program(data, USAGE_MSG, 1);
	data = ft_init_data(argc, argv);
	if (!ft_is_sorted(data->a->list, data->a->order))
	{
		ft_sort_stack(data);
	}
	ft_end_program(data, NULL, 0);
}
