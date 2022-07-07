# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 18:42:17 by minsuki2          #+#    #+#              #
#    Updated: 2022/07/05 09:16:13 by minsuki2         ###   ########.fr        #
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
FTPRINTF_DIR	= ft_printf/
FTPRINTF		= libftprintf.a

LIBFT_DIR 		=	libft/
LIBFT 			=	libft.a
EXE				=	simulator

SRCS			=	exec.c				\
					exec_utils.c		\
					ft_simple_atoi.c

OBJS		=	$(SRCS:.c=.o)

all: $(FTPRINTF_DIR)$(FTPRINTF) $(EXE)

$(FTPRINTF_DIR)$(FTPRINTF):
	$(MAKE_C) $(FTPRINTF_DIR)

$(EXE): $(SRCS)
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	$(CC) -g $(CFLAGS) $(SRCS) $(FTPRINTF_DIR)$(FTPRINTF) $(INC)./ $(INC)$(FTPRINTF_DIR) $(INC)$(LIBFT_DIR) -o $@
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@

%.o: %.c #$(HADS)
	@echo $@ Making...
	$(CC) $(CFLAGS) $(COMPILE) $< $(INC)$(FTPRINTF_DIR) $(INC)$(LIBFT_DIR) -o $@

clean:
	$(MAKE_C) $(LIBFT_DIR) clean
	$(MAKE_C) $(FTPRINTF_DIR) clean
	@echo
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(SRCS:.c=.o)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> Delete List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(LIBFT_DIR)$(LIBFT)
	@$(RM) $(FTPRINTF_DIR)$(FTPRINTF)
	@$(RM) $(EXE)
	@echo ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@echo

.PHONY: all clean fclean
