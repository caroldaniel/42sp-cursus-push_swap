/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:55:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/19 11:48:53 by cado-car         ###   ########.fr       */
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

int	ft_atoi_mod(t_data *data, const char *str)
{
	size_t	i;
	int		sign;
	int		total;
	int		prev;

	i = 0;
	sign = 1;
	total = 0;
	prev = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = total;
		total = total * 10 + (str[i] - '0');
		if (total < prev)
			ft_end_program(data, 6);
		i++;
	}
	return (total * sign);
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
		free(args[i++]);
	free(args);
}
