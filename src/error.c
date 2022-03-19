/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:17:23 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/18 19:19:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CALL FREE FUNCTIONS AND EXIT PROGRAM
*/

void	ft_end_program(t_data *data, char *exit_message, int exit_number)
{
	if (data)
	{
		if (data->a)
			ft_free_stack(data->a);
		if (data->b)
			ft_free_stack(data->b);
		if (data->pos)
			free(data->pos);
		if (data->tmp)
			free(data->tmp);
		free(data);
	}
	if (exit_number)
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
