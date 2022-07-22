# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 18:42:17 by minsuki2          #+#    #+#              #
#    Updated: 2022/07/22 21:10:03 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
COMPILE			= -c
INC 			= -I
RM 				= rm -vf
AR 				= ar
ARFLAGS 		= -rcus
MAKE_C 			= make -C
MANDATORY_DIR 	= ./
BONUS_DIR 		= ./
TARGET_DIR 		= $(MANDATORY_DIR)

LIBFT_DIR 		=	libft/
LIBFT 			=	libft.a
NAME	 		=	push_swap
BONUS_NAME		=	checker

SRCS			=	push_swap.c						\
					quick_sort.c					\
					push_swap_utils.c				\
					push_swap_utils2.c				\
					stack_lst_utils.c				\
					check_utils.c					\
					push_swap_command.c				\
					case_under_five.c				\
					wall_sorting.c					\
					ft_simple_atoi.c

BONUS_SRCS		=	push_swap_bonus.c				\
					push_swap_utils_bonus.c			\
					push_swap_command_bonus.c		\
					stack_lst_utils_bonus.c			\
					ft_simple_atoi_bonus.c

HADS			=	$(MANDATORY_DIR)push_swap.h
OBJS			=	$(addprefix $(MANDATORY_DIR), $(SRCS:.c=.o))

all: $(LIBFT_DIR)$(LIBFT) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE_C) $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)$(LIBFT) $(INC)$(LIBFT_DIR) -o $@
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	@echo Push swap Compiled!

%.o: %.c
	@echo $@ Making...
	$(CC) $(CFLAGS) $(COMPILE) $< $(INC)$(LIBFT_DIR) -o $@

clean:
	$(MAKE_C) $(LIBFT_DIR) clean
	@echo
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(addprefix $(MANDATORY_DIR), $(SRCS:.c=.o))
	@$(RM) $(addprefix $(BONUS_DIR), $(BONUS_SRCS:.c=.o))
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(LIBFT_DIR)$(LIBFT)
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

re:
	@make fclean
	@make all

bonus: $(LIBFT_DIR)$(LIBFT)
	@$(MAKE) \
	"NAME 			=	$(BONUS_NAME)"									\
	"OBJS			=	$(addprefix $(BONUS_DIR), $(BONUS_SRCS:.c=.o))"	\
	"HADS			=	$(BONUS_DIR)push_swap_bonus.h"					\
	all

.PHONY: all clean fclean re bonus
