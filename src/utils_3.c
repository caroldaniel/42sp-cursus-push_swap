/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:55:02 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 11:30:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	FT_ABS
**	------------
**	DESCRIPTION
**	Converts number to its absolute value.  
**	PARAMETERS
**	#1. Number to be converted.
**	RETURN VALUES
**	The absolute integer value converted.
*/

int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

/*	FT_ATOI_MOD
**	------------
**	DESCRIPTION
**	Does the same as the classical atoi but with a few adaptations in order to 
**	exit program at first bad conversion, handles MIN and MAX ints and does not
**	allows for unprintable characters nor other characters of any form among 
**	string. It also exits at no numeric occurance.  
**	PARAMETERS
**	#1. The t_data struct in which all arguments are kept;
**	#2. The position in which to convert string from argument's array. 
**	RETURN VALUES
**	The integer converted.
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

/*	FT_ARGS_COPY
**	------------
**	DESCRIPTION
**	Copies all arguments from a list of `size` strings into a new list of 
**	strings.  
**	PARAMETERS
**	#1. The char ** list of strings to copy;
**	#2. The size of the list. 
**	RETURN VALUES
**	The new list.
*/

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
