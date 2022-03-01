/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:53:24 by cado-car          #+#    #+#             */
/*   Updated: 2022/02/28 20:46:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0)
		ft_error(data, USAGE_MSG, 1);
	data = ft_init_data(argc, argv);
	if (!ft_is_sorted(data->a->list, data->a->order))
		printf("Stack NOT sorted.\n");
	else
		printf("Stack sorted!\n");
	return (0);
}
