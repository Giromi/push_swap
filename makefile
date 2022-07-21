	# **************************************************************************** #
	#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 18:42:17 by minsuki2          #+#    #+#              #
#    Updated: 2022/07/21 13:29:44 by minsuki2         ###   ########.fr        #
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
FTPRINTF_DIR	= ft_printf/
FTPRINTF		= libftprintf.a
TARGET_DIR 		= $(MANDATORY_DIR)

LIBFT_DIR 		=	libft/
LIBFT 			=	libft.a
NAME	 		=	push_swap

SRCS			=	push_swap.c						\
					push_swap_utils.c				\
					push_swap_command.c				\
					push_swap_command_utils.c		\
					basic_command.c					\
					ft_simple_atoi.c				\
					case_under_five.c				\
					case_under_five_utils.c			\
					wall_sorting.c					\
					quick_sort.c
			# HAD_FILES 		=	ft_printf.h
	# BONUS_HAD_FILES =	ft_printf_bonus.h

# MINITALK_HADS = $(HAD_FILES))

MINITALK_OBJS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_SRC_FILES:.c=.o))
# MINITALK_HADS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_HAD_FILES))

# OBJS = $(MINITALK_OBJS)
OBJS		=	$(addprefix $(MANDATORY_DIR), $(SRCS:.c=.o))

all: $(FTPRINTF_DIR)$(FTPRINTF) $(NAME)

$(FTPRINTF_DIR)$(FTPRINTF):
	$(MAKE_C) $(FTPRINTF_DIR)

$(NAME): $(OBJS)
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	$(CC) $(CFLAGS)  $^ $(FTPRINTF_DIR)$(FTPRINTF) -o $@
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	@echo Push swap Compiled!
#$(CC) -g -fsanitize=address $(CFLAGS) $(addprefix $(MANDATORY_DIR), $(SRCS)) $(FTPRINTF_DIR)$(FTPRINTF) $(INC)$(FTPRINTF_DIR) $(INC)$(LIBFT_DIR) -o $@

%.o: %.c #$(HADS)
	@echo $@ Making...
	$(CC) $(CFLAGS) $(COMPILE) $< $(INC)$(FTPRINTF_DIR) $(INC)$(LIBFT_DIR) -o $@

clean:
	$(MAKE_C) $(LIBFT_DIR) clean
	$(MAKE_C) $(FTPRINTF_DIR) clean
	@echo
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(addprefix $(MANDATORY_DIR), $(SRCS:.c=.o))
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(LIBFT_DIR)$(LIBFT)
	@$(RM) $(FTPRINTF_DIR)$(FTPRINTF)
	@$(RM) $(NAME)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo
# @$(RM) $(NAME)

re:
	@make fclean
	@make all

bonus: $(LIBFT_DIR)$(LIBFT)
	@$(MAKE) \
	"TARGET_DIR 	=	$(BONUS_DIR)"												\
	"OBJS		=	$(addprefix $(BONUS_DIR), $(SRCS:.c=.o))"					\
	all

.PHONY: all clean fclean re bonus
