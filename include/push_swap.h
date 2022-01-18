/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:58:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/01/18 15:22:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

// Stack struct
typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

// Basic input / output error management
int		check_args(char **argv);
void	error(char *exit_message, int exit_number);

// Stack management
t_stack	*get_arg_list(int argc, char **argv);
t_stack	*stack_new(int number);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
t_stack	*ft_stack_last(t_stack *stack);
size_t	ft_stack_len(t_stack *stack);
void	print_stack(char *name, t_stack *stack);
int		has_repeated_args(t_stack *stack);
int		is_number_in_stack(int number, t_stack *stack);

// Operations
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif