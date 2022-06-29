/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:23 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/29 08:57:58 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"
# define ERROR -1

typedef struct s_stack
{
	int num;
	int idx;
	struct s_stack *next;
} t_stack;

typedef struct s_cursor
{
	t_stack *stack_a;
	t_stack *stack_b;
} t_cursor;

int ft_isspace(int);

#endif
