# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 20:00:57 by cado-car          #+#    #+#              #
#    Updated: 2022/03/20 11:52:31 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
NAME_BONUS		= checker
LIBFT			= libft.a

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/
OBJ_PATH		= ./obj/
INCLUDE 		= ./include/

#compilation
CC 				= gcc
CF 				= -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)

SRC 			= main.c \
				args.c \
				init.c \
				error.c \
				list_utils_1.c \
				list_utils_2.c \
				stack_op_1.c \
				stack_op_2.c \
				utils_1.c \
				utils_2.c \
				utils_3.c \
				sort.c \
				sort_utils_1.c \
				sort_utils_2.c \
				
SRC_BONUS		= checker.c	\
				utils_bonus.c \
				args.c \
				init.c \
				error.c \
				list_utils_1.c \
				list_utils_2.c \
				stack_op_1.c \
				stack_op_2.c \
				utils_1.c \
				utils_2.c \
				utils_3.c \
				sort.c \
				sort_utils_1.c \
				sort_utils_2.c \

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))
OBJ_BONUS		= $(addprefix $(OBJ_PATH), $(notdir $(SRC_BONUS:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: 	$(SRC_PATH)%.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating push_swap executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)


re:				fclean all

$(NAME_BONUS):	$(OBJ_BONUS)
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating checker executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME_BONUS) $(OBJ_BONUS) -L $(LIBFT_PATH) -lft
				@printf "$(GR)Done!$(RC)\n\n"

bonus:			$(NAME_BONUS)

rebonus:		fclean bonus

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJ_BONUS) $(OBJDIR)
				@printf "$(RE)push_swap objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)
				@printf "$(RE)Executables removed!$(RC)\n\n"

.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m