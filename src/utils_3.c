/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:55:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/18 19:57:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** RETURN ABSOLUTE VALUE OF NUMBER
*/

int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

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
