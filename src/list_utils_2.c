/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:44:28 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:09:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	FT_CLEAR_LIST
**	------------
**	DESCRIPTION
**	Frees all elements of list given.
**	PARAMETERS
**	#1. The t_list struct;
**	RETURN VALUES
**	-
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
**	FT_LIST_LEN
**	------------
**	DESCRIPTION
**	Gets the length of the given list.
**	PARAMETERS
**	#1. The t_list struct;
**	RETURN VALUES
**	The unsigned integer correspodent to the size of given list.
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
**	FT_IS_SORTED
**	------------
**	DESCRIPTION
**	Checks if list is sorted in the order given (ascending or descending).
**	PARAMETERS
**	#1. The t_list struct;
**	#2. The id for the order desired.
**	RETURN VALUES
**	Returns 0 for not sorted list, or 0 for sorted.
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
