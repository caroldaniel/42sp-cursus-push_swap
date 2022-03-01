/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:46:56 by cado-car          #+#    #+#             */
/*   Updated: 2022/02/28 19:57:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** SWAP FIRST TWO ELEMENTS OF LINKED LIST
*/

void	ft_list_swap(t_list **list)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	b = (*list)->next;
	if (!b)
		return ;
	a->next = b->next;
	b->next = a;
	*list = b;
}

/*
** PUSH FIRST ELEMENT OF LIST TO TOP OF ANOTHER
*/

void	ft_list_push(t_list **from, t_list **to)
{
	t_list	*moved;

	moved = *from;
	*from = (*from)->next;
	moved->next = NULL;
	ft_list_add_front(to, moved);
}

/*
** ROTATE LIST
*/

void	ft_list_rotate(t_list **list)
{
	t_list	*moved;

	moved = *list;
	*list = (*list)->next;
	moved->next = NULL;
	ft_list_add_back(list, moved);
}

/*
** REVERSE ROTATE LIST
*/

void	ft_list_reverse_rotate(t_list **list)
{
	t_list	*moved;
	t_list	*temp;
	size_t	list_size;
	size_t	i;

	list_size = ft_list_len(*list);
	moved = ft_list_last(*list);
	moved->next = *list;
	*list = moved;
	temp = *list;
	i = 0;
	while (++i < list_size)
		temp = temp->next;
	temp->next = NULL;
}
