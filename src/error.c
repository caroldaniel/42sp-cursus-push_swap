/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:17:23 by cado-car          #+#    #+#             */
/*   Updated: 2022/02/28 19:39:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CALL FREE FUNCTIONS AND EXIT PROGRAM
*/

void	ft_error(t_data *data, char *exit_message, int exit_number)
{
	if (data)
	{
		if (data->a)
			ft_free_stack(data->a);
		if (data->b)
			ft_free_stack(data->b);
		free(data);
	}
	ft_putstr_fd(exit_message, 2);
	exit(exit_number);
}

/*
** FREE STACK AND LIST STRUCTS
*/

void	ft_free_stack(t_stack *stack)
{
	if (stack->list)
		free(stack->list);
	free(stack);
}
