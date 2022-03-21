/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:48:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:15:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	

/*	FT_SORT_STACKS
**	------------
**	DESCRIPTION
**	Redirects the stacks to their corresponding phases of the sorting algorithm.
**	PARAMETERS
**	#1. The t_data struct with all data stored in it.
**	RETURN VALUES
**	-
*/

void	ft_sort_stack(t_data *data)
{
	ft_push_away(data);
	ft_push_back(data);
	ft_align(data);
}
