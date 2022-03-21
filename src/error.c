/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:17:23 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 11:23:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	FT_END_PROGRAM
**	------------
**	DESCRIPTION
**	Finishes all processes and free all memory allocated on the t_data struct. 
**	PARAMETERS
**	#1. The t_data struct with all allocated memory within it;
**	#2. The number of the exit code. 
**	RETURN VALUES
**	-
*/

void	ft_end_program(t_data *data, int exit_number)
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
		if (data->args)
			ft_free_args(data->args);
		free(data);
	}
	if (exit_number > 0)
		ft_putstr_fd(ERROR_MSG, 2);
	else if (exit_number == -1)
		ft_putstr_fd(BONUS_OK, 1);
	else if (exit_number == -2)
		ft_putstr_fd(BONUS_KO, 1);
	exit(exit_number);
}

/*	FT_FREE_STACK
**	------------
**	DESCRIPTION
**	Frees all memory allocated within the t_stack struct. 
**	PARAMETERS
**	#1. The t_stack struct
**	RETURN VALUES
**	-
*/

void	ft_free_stack(t_stack *stack)
{
	if (stack->list)
		ft_clear_list(&stack->list);
	free(stack);
}

/*	FT_FREE_ARGS
**	------------
**	DESCRIPTION
**	Free all memory allocated within the args variable inside the t_data struct.
**	PARAMETERS
**	#1. The list of strings passed as arguments
**	RETURN VALUES
**	-
*/

void	ft_free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
