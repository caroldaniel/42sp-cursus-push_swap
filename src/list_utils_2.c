/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:44:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/19 08:03:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CLEAR LINKED LIST
*/

void	ft_clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

/*
** GET LIST LENGTH
*/

size_t	ft_list_len(t_list *list)
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

/*
** CHECK IF LIST IS SORTED
*/

int	ft_is_sorted(t_list *list, int id)
{
	t_list	*aux;
	t_list	*next;

	aux = list;
	next = list->next;
	while (next)
	{
		if (aux->number >= next->number && id == ASCENDING)
			return (0);
		if (aux->number <= next->number && id == DESCENDING)
			return (0);
		aux = aux->next;
		next = next->next;
	}
	return (1);
}
