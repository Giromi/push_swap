	# **************************************************************************** #
	#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 18:42:17 by minsuki2          #+#    #+#              #
#    Updated: 2022/07/21 15:31:44 by minsuki2         ###   ########.fr        #
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
MANDATORY_DIR 	= mandatory/
BONUS_DIR 		= bonus/
TARGET_DIR 		= $(MANDATORY_DIR)

LIBFT_DIR 		=	libft/
LIBFT 			=	libft.a
NAME	 		=	push_swap

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

HADS			=	$(MANDATORY_DIR)push_swap.h

HADS			=	$(BONUS_DIR)push_swap_bonus.h


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
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(LIBFT_DIR)$(LIBFT)
	@$(RM) $(NAME)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

re:
	@make fclean
	@make all

bonus: $(LIBFT_DIR)$(LIBFT)
	@$(MAKE) \
	"TARGET_DIR 	=	$(BONUS_DIR)"												\
	"OBJS		=	$(addprefix $(BONUS_DIR), $(SRCS:.c=.o))"					\
	"OBJS		=	$(addprefix $(BONUS_DIR), $(SRCS:.c=.o))"					\
	all

.PHONY: all clean fclean re bonus
