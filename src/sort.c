/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:48:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/19 11:48:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	

void	ft_sort_stack(t_data *data)
{
	ft_push_away(data);
	ft_push_back(data);
	ft_align(data);
}
