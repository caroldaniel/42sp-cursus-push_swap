/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:42:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/02 15:01:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** CHECK IF DIGIT NUMERICAL OR SYMBOLICAL
*/

int	ft_isnumeric(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

/*
** COUNT HOW MANY NUMBERS ON WHOLE STACK ARE LOWER THEN THE NUMBER ON TOP 
*/

size_t	ft_count_lowers(t_stack *stack)
{
	t_list	*aux;
	int		first;
	size_t	lowers;

	if (!stack->list)
		return (0);
	aux = stack->list;
	first = aux->number;
	lowers = 0;
	while (aux)
	{
		if (first < aux->number)
			lowers++;
		aux = aux->next;
	}
	return (lowers);
}

/*
** FIND STACK SPLIT COEFICIENT < -- > found through trial and error 
*/

void	ft_find_coef(t_data	*data)
{
	if (data->a->size >= 50)
	{
		data->coef[A] = 0.67;
		data->coef[B] = 0.2;
	}
	else
	{
		data->coef[A] = 0.33;
		data->coef[B] = 0.5;
	}
}

/*
** PRINT MOVEMENTS
*/

void	ft_print_movement(int operation, int stack_id)
{
	if (operation == SWAP)
		write(1, "s", 1);
	else if (operation == PUSH)
		write(1, "p", 1);
	else if (operation == ROTATE)
		write(1, "r", 1);
	else if (operation == REVERSE_ROTATE)
		write(1, "rr", 2);
	if (stack_id == A)
		write(1, "a\n", 2);
	else if (stack_id == B)
		write(1, "b\n", 2);
	else if (stack_id == R && operation != SWAP)
		write(1, "r\n", 2);
	else
		write(1, "s\n", 2);
}
