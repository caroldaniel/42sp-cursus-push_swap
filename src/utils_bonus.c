/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:49:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/20 10:25:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CREATE NEW COMMAND FOR INSTRUCTION LIST
*/

t_move	*ft_instruction_new(char *command)
{
	t_move	*new;

	new = malloc(sizeof(t_move));
	if (!new || !command)
		return (NULL);
	new->command = ft_strdup(command);
	new->next = NULL;
	return (new);
}

/*
** FIND LAST ELEMENT ON INSTRUCTION LIST
*/
t_move	*ft_instruction_last(t_move *list)
{
	t_move	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

/*
** ADD ITEM AFTER LAST ELEMENT OF LIST
*/
void	ft_instruction_add_back(t_move **list, t_move *new)
{
	t_move	*temp;

	if (!new)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		temp = ft_instruction_last(*list);
		temp->next = new;
	}
}

/*
** CLEAR INSTRUCTIONS LINKED LIST
*/

void	ft_clear_instruction_list(t_move **list)
{
	t_move	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->command);
		free(temp);
	}
}

/*
** GET INSTRUCTIONS LIST LENGTH
*/

size_t	ft_instruction_list_len(t_move *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
