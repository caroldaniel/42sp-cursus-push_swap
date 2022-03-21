/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:49:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 11:53:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	FT_LIST_NEW
**	------------
**	DESCRIPTION
**	Create new t_list element with given integer.
**	PARAMETERS
**	#1. The integer.
**	RETURN VALUES
**	Returns a t_list struct populated with the number, or NULL if error.
*/

t_list	*ft_list_new(int number)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

/*
**	FT_LIST_LAST
**	------------
**	DESCRIPTION
**	Searches for the last element of given list.
**	PARAMETERS
**	#1. The t_list struct.
**	RETURN VALUES
**	Returns the pointer for the last element, or NULL if list is empty.
*/

t_list	*ft_list_last(t_list *list)
{
	t_list	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

/*
**	FT_LIST_AT
**	------------
**	DESCRIPTION
**	Searches for the element correspondent to the index given.
**	PARAMETERS
**	#1. The t_stack struct in which the element is in;
**	#2. The index desired.
**	RETURN VALUES
**	Returns the integer kept at the t_list index position.
*/

int	ft_list_at(t_stack *stack, size_t index)
{
	t_list	*elem;
	size_t	i;

	i = 0;
	elem = stack->list;
	while (i != index)
	{
		i++;
		elem = elem->next;
	}
	return (elem->number);
}

/*
**	FT_LIST_ADD_BACK
**	------------
**	DESCRIPTION
**	Adds a new element at the end of the linked list.
**	PARAMETERS
**	#1. The t_list struct;
**	#2. The new element.
**	RETURN VALUES
**	-
*/

void	ft_list_add_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		temp = ft_list_last(*list);
		temp->next = new;
	}
}

/*
**	FT_LIST_ADD_FRONT
**	------------
**	DESCRIPTION
**	Adds a new element at the beggining of the linked list.
**	PARAMETERS
**	#1. The t_list struct;
**	#2. The new element.
**	RETURN VALUES
**	-
*/

void	ft_list_add_front(t_list **list, t_list *new)
{
	t_list	*elem;

	if (*list == NULL)
		*list = new;
	else
	{
		elem = new;
		elem->next = *list;
		*list = elem;
	}
}
