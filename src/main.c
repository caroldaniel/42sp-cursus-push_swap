/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:53:24 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 11:10:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	DESCRIPTION
**	The idea of push_swap is to get from the passed parameters a stack of 
**	integers and sort it with a limited number of movements and only two stacks
**	at your disposal. The execution of the program starts here, with the 
**	initialization of the t_data struct (in which all information will be stored)
**	and will receive the argv, parse it into a t_stack struct and sort it
**	appropriately.
*/

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0)
		exit(1);
	data = ft_init_data(argc, argv);
	if (!ft_is_sorted(data->a->list, data->a->order))
		ft_sort_stack(data);
	ft_end_program(data, 0);
}
