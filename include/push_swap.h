/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:58:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/02/28 21:18:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

// Stack IDs - A, B or R (for both)
# define A		0
# define B		1
# define R		2

// Stack order enumerator
enum e_order{
	ASCENDING,
	DESCENDING
};

// Linked list struct 
typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

// Stack struct
typedef struct s_stack
{
	t_list	*list;
	size_t	size;
	size_t	range;
	int		order;
}			t_stack;

// Project data struct
typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	
}			t_data;

# define USAGE_MSG	"Wrong usage. Use:\n\t./push_swap <number_list>\n"
# define ERROR_MSG	"Error\n"

// Structs initialization
t_data	*ft_init_data(int argc, char **argv);
t_stack	*ft_init_stack(char **args, int id);

// Argument and stack management
t_list	*ft_get_stack_list(char **stack);
int		ft_check_args(char **stack);
void	ft_stack_range(t_stack **stack);

// Error management
void	ft_error(t_data *data, char *exit_message, int exit_number);
void	ft_free_stack(t_stack *stack);

// Linked list management and utils
t_list	*ft_list_new(int number);
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
void	ft_clear_list(t_list **list);
size_t	ft_list_len(t_list *list);
int		ft_is_sorted(t_list *list, int id);

// Other utils
void	ft_print_stack(char *name, t_list *list);
int		ft_isnumeric(int c);

// Operations
void	ft_list_swap(t_list **list);
void	ft_list_push(t_list **from, t_list **to);
void	ft_list_rotate(t_list **list);
void	ft_list_reverse_rotate(t_list **list);

#endif