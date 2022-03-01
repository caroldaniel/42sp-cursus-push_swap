/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:49:39 by cado-car          #+#    #+#             */
/*   Updated: 2022/02/28 19:55:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CREATE NEW ITEM FOR LIST
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
** FIND LAST ELEMENT ON LIST
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
** ADD ITEM AFTER LAST ELEMENT OF LIST
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
** ADD ITEM BEFORE FIRST ELEMENT OF LIST
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
