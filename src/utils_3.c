/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:55:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/20 19:00:38 by cado-car         ###   ########.fr       */
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
** CONVERTS ARGUMENT LIST 
*/

int	ft_atoi_mod(t_data *data, int position)
{
	size_t	i;
	int		sign;
	long	total;

	i = 0;
	sign = 1;
	total = 0;
	if (data->args[position][i] == '+' || data->args[position][i] == '-')
		if (data->args[position][i++] == '-')
			sign *= (-1);
	if (!ft_isdigit(data->args[position][i]))
		ft_end_program(data, 6);
	while (data->args[position][i] >= '0' && data->args[position][i] <= '9')
	{
		if (sign == -1)
			total = total * 10 - (data->args[position][i] - '0');
		else
			total = total * 10 + (data->args[position][i] - '0');
		if (total < -2147483648 || total > 2147483647)
			ft_end_program(data, 6);
		i++;
	}
	if (!ft_isdigit(data->args[position][i]) && data->args[position][i] != 0)
		ft_end_program(data, 6);
	return ((int)total);
}

char	**ft_args_copy(char **args, int size)
{
	char	**copied;
	int		i;

	copied = (char **)malloc(sizeof(char *) * (size + 1));
	if (!copied)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copied[i] = (char *)malloc(sizeof(char) * (ft_strlen(args[i]) + 1));
		if (!copied[i])
		{
			while (--i >= 0)
				free(copied[i]);
			free(copied);
			return (NULL);
		}
		ft_strlcpy(copied[i], args[i], ft_strlen(args[i]) + 1);
		i++;
	}
	copied[i] = NULL;
	return (copied);
}

void	ft_free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
