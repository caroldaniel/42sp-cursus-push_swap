/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:58:11 by cado-car          #+#    #+#             */
/*   Updated: 2022/03/21 12:00:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

// Stack IDs - A, B or R (for both)
# define A		0
# define B		1
# define R		2

// Stack order enumerator
enum e_order{
	ASCENDING,
	DESCENDING
};

// Stack order enumerator
enum e_operation{
	ROTATE,
	REVERSE_ROTATE,
	SWAP,
	PUSH
};

// Linked list struct 
typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

// Stack struct
typedef struct s_stack
{
	t_list	*list;
	size_t	size;
	size_t	range;
	int		order;
}	t_stack;

// Project data struct
typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	float	coef[2];
	int		*pos;
	int		*tmp;
	int		operate;
	int		counter;
	void	(*ft[2])(struct s_data *, int, int);
}	t_data;

// Bonus struct for command list
typedef struct s_move
{
	char			*command;
	struct s_move	*next;
}	t_move;

# define ERROR_MSG	"Error\n"
# define BONUS_OK	"OK\n"
# define BONUS_KO	"KO\n"

// Structs initialization
t_data	*ft_init_data(int argc, char **argv);
void	ft_init_stacks(t_data *data);

// Argument and stack management
int		ft_check_args(t_data *data);
void	ft_get_stack_list(t_data *data);
void	ft_stack_range(t_stack **stack);

// Error management
void	ft_end_program(t_data *data, int exit_number);
void	ft_free_stack(t_stack *stack);
void	ft_free_args(char **args);

// Linked list management and utils
t_list	*ft_list_new(int number);
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
void	ft_clear_list(t_list **list);
size_t	ft_list_len(t_list *list);
int		ft_list_at(t_stack *stack, size_t index);
int		ft_is_sorted(t_list *list, int id);

// Stack operations
void	ft_stack_swap(t_stack **stack);
void	ft_stack_push(t_data *data, int id);
void	ft_stack_rotate(t_stack **stack);
void	ft_stack_reverse_rotate(t_stack **stack);

// Movements
void	ft_swap(t_data *data, int id, int is_print);
void	ft_push(t_data *data, int id, int is_print);
void	ft_rotate(t_data *data, int id, int is_print);
void	ft_reverse_rotate(t_data *data, int id, int is_print);

// Sorting algorithms
void	ft_sort_stack(t_data *data);
void	ft_push_away(t_data *data);
void	ft_push_back(t_data *data);
void	ft_align(t_data *data);
void	ft_sort_five(t_data *data);
void	ft_calculate_best_movement(t_data *data);
void	ft_move(t_data *data);

// Other utils
int		ft_abs(int number);
int		ft_atoi_mod(t_data *data, int position);
char	**ft_args_copy(char **args, int size);
size_t	ft_count_lowers(t_stack *stack);
size_t	ft_count_moves(int *position);
void	ft_find_coef(t_data	*data);
void	ft_print_movement(int operation, int stack_id);
void	ft_print_stack(char *name, t_list *list);
int		ft_get_push_away_id(t_data *data);
int		ft_get_sort_five_rotate_id(t_data *data);
int		ft_get_sort_five_swap_id(t_data *data);
int		ft_get_position(t_stack *stack, int nb);

// BONUS PART
// Instruction list management and utils
t_move	*ft_instruction_new(char *command);
t_move	*ft_instruction_last(t_move *list);
void	ft_instruction_add_back(t_move **list, t_move *new);
void	ft_clear_instruction_list(t_move **list);
size_t	ft_instruction_list_len(t_move *list);

// Commands management
t_move	*ft_read_commands(void);
void	ft_run_all(t_data *data, t_move	**commands);
int		ft_execute_commands(t_data *data, char *command);

#endif