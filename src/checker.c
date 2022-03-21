/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:06:42 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 09:32:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;
	t_move	*commands;

	data = NULL;
	if (argc - 1 == 0)
		exit(1);
	data = ft_init_data(argc, argv);
	commands = ft_read_commands();
	if (commands)
		ft_run_all(data, &commands);
	if (!ft_is_sorted(data->a->list, data->a->order) || data->b->size > 0)
		ft_end_program(data, -2);
	ft_end_program(data, -1);
}

t_move	*ft_read_commands(void)
{
	t_move	*commands;
	t_move	*new;
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (NULL);
	commands = ft_instruction_new(line);
	while (1)
	{
		free(line);
		line = get_next_line(0);
		if (!line)
			break ;
		new = ft_instruction_new(line);
		ft_instruction_add_back(&commands, new);
	}
	return (commands);
}

void	ft_run_all(t_data *data, t_move	**commands)
{
	t_move	*tmp;

	tmp = *commands;
	while (tmp)
	{
		if (!ft_execute_commands(data, tmp->command))
		{
			ft_clear_instruction_list(commands);
			ft_end_program(data, 7);
		}
		tmp = tmp->next;
	}
	ft_clear_instruction_list(commands);
}

int	ft_execute_commands(t_data *data, char *command)
{
	if (!ft_strncmp("sa\n", command, 3))
		ft_swap(data, A, 0);
	else if (!ft_strncmp("sb\n", command, 3))
		ft_swap(data, B, 0);
	else if (!ft_strncmp("ss\n", command, 3))
		ft_swap(data, R, 0);
	else if (!ft_strncmp("pa\n", command, 3))
		ft_push(data, A, 0);
	else if (!ft_strncmp("pb\n", command, 3))
		ft_push(data, B, 0);
	else if (!ft_strncmp("ra\n", command, 3))
		ft_rotate(data, A, 0);
	else if (!ft_strncmp("rb\n", command, 3))
		ft_rotate(data, B, 0);
	else if (!ft_strncmp("rr\n", command, 3))
		ft_rotate(data, R, 0);
	else if (!ft_strncmp("rra\n", command, 4))
		ft_reverse_rotate(data, A, 0);
	else if (!ft_strncmp("rrb\n", command, 4))
		ft_reverse_rotate(data, B, 0);
	else if (!ft_strncmp("rrr\n", command, 4))
		ft_reverse_rotate(data, R, 0);
	else
		return (0);
	return (1);
}
