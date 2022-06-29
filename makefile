# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 18:42:17 by minsuki2          #+#    #+#              #
#    Updated: 2022/06/26 16:51:52 by minsuki2         ###   ########.fr        #
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
SEND_OUT		=	client
RECEIVE_OUT		=	server
NAME	 		=	$(SEND_OUT) $(RECEIVE_OUT)

SRC_DIR				=	srcs/
SEND_SRCS			=	sender.c
RECEIVE_SRCS		=	receiver.c
SEND_SRCS_BONUS		=	sender_bonus.c
RECEIVE_SRCS_BONUS	=	receiver_bonus.c
# HAD_FILES 		=	ft_printf.h
# BONUS_HAD_FILES =	ft_printf_bonus.h

# MINITALK_HADS = $(HAD_FILES))

# MINITALK_OBJS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_SRC_FILES:.c=.o))
# MINITALK_HADS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_HAD_FILES))

# OBJS = $(MINITALK_OBJS)
# HADS = $(MINITALK_HADS)

SEND_OBJS		=	$(addprefix $(MANDATORY_DIR), $(SEND_SRCS:.c=.o))
RECEIVE_OBJS	=	$(addprefix $(MANDATORY_DIR), $(RECEIVE_SRCS:.c=.o))

all: $(FTPRINTF_DIR)$(FTPRINTF) $(NAME)

$(FTPRINTF_DIR)$(FTPRINTF):
	$(MAKE_C) $(FTPRINTF_DIR)

$(NAME): $(SEND_OBJS) $(RECEIVE_OBJS)
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	$(CC) $(CFLAGS) $(SEND_OBJS) $(FTPRINTF_DIR)$(FTPRINTF) -o $(SEND_OUT)
	$(CC) $(CFLAGS) $(RECEIVE_OBJS) $(FTPRINTF_DIR)$(FTPRINTF) -o $(RECEIVE_OUT)
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	@echo client \<=\> sever Compiled!

%.o: %.c #$(HADS)
	@echo $@ Making...
	$(CC) $(CFLAGS) $(COMPILE) $< $(INC)$(FTPRINTF_DIR) $(INC)$(LIBFT_DIR) -o $@

clean:
	$(MAKE_C) $(LIBFT_DIR) clean
	@echo
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(MANDATORY_DIR)$(SEND_SRCS:.c=.o)
	@$(RM) $(MANDATORY_DIR)$(RECEIVE_SRCS:.c=.o)
	@$(RM) $(MANDATORY_DIR)$(SEND_SRCS_BONUS:.c=.o)
	@$(RM) $(MANDATORY_DIR)$(RECEIVE_SRCS_BONUS:.c=.o)
	@$(RM) $(BONUS)$(SEND_SRCS:.c=.o)
	@$(RM) $(BONUS)$(RECEIVE_SRCS:.c=.o)
	@$(RM) $(BONUS)$(SEND_SRCS_BONUS:.c=.o)
	@$(RM) $(BONUS)$)$(RECEIVE_SRCS_BONUS:.c=.o)
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
	"SEND_OBJS		=	$(addprefix $(BONUS_DIR), $(SEND_SRCS_BONUS:.c=.o))"		\
	"RECEIVE_OBJS	=	$(addprefix $(BONUS_DIR), $(RECEIVE_SRCS_BONUS:.c=.o))" 	\
	"TARGET_DIR 	=	$(BONUS_DIR)"												\
	all

.PHONY: all clean fclean re bonus
