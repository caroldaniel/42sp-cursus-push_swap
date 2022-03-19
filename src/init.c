/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:30 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/18 19:46:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_data	*ft_init_data(int argc, char **argv)
{
	char	**args;
	t_data	*data;

	data = NULL;
	if (argc - 1 == 1)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	if (!ft_check_args(args))
		ft_end_program(data, ERROR_MSG, 2);
	data = malloc(sizeof(t_data));
	if (!data)
		ft_end_program(data, ERROR_MSG, 3);
	data->pos = (int *)malloc(sizeof(int) * 2);
	data->tmp = (int *)malloc(sizeof(int) * 2);
	data->a = ft_init_stack(args, A);
	data->b = ft_init_stack(NULL, B);
	data->ft[ROTATE] = ft_rotate;
	data->ft[REVERSE_ROTATE] = ft_reverse_rotate;
	if (!data->pos || !data->tmp || !data->a || !data->b)
		ft_end_program(data, ERROR_MSG, 5);
	return (data);
}

t_stack	*ft_init_stack(char **args, int id)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (args == NULL)
		stack->list = NULL;
	else
	{
		stack->list = ft_get_stack_list(args);
		if (!stack->list)
		{
			free(stack);
			return (NULL);
		}
	}
	ft_stack_range(&stack);
	if (id == A)
		stack->order = ASCENDING;
	if (id == B)
		stack->order = DESCENDING;
	return (stack);
}
