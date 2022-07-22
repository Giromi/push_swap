/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:54:20 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 21:08:07 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft.h"
# define ERROR		-1
# define SUCCESS	0
# define BIT_INT	0B00000000
# define BIT_ALL	0B11111111
# define BIT_SA		0B00000001
# define BIT_SB		0B00000010
# define BIT_RA		0B00000100
# define BIT_RB		0B00001000
# define BIT_RRA	0B00010000
# define BIT_RRB	0B00100000
# define BIT_PA		0B01000000
# define BIT_PB		0B10000000
# define BIT_SS		0B00000011
# define BIT_RR		0B00001100
# define BIT_RRR	0B00110000
# define VAL_INT_MIN	2147483648
# define VAL_INT_MAX	2147483647

typedef struct s_stack
{
	int				num;
	int				idx;
	char			spot;
	struct s_stack	*next;
	struct s_stack	*priv;
}	t_stack;

typedef struct s_cursor
{
	t_stack			*cur_a;
	int				cnt_a;
	t_stack			*cur_b;
	int				cnt_b;
	char			*order;
}	t_cursor;

char	*ft_strchr_null(const char *s, int c);
void	stack_head_set(t_cursor *head, t_stack *first);
t_stack	*stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst, t_stack *new);
int		stdio_input(t_cursor *head);
int		stack_lstadd_back(t_stack **lst, t_stack *new);
void	lst_clean(t_stack **lst);
void	stack_lstfclean(t_cursor *head);
int		sx(t_stack *top);
int		rx(t_cursor *head, t_stack *top);
int		rrx(t_cursor *head, t_stack *top);
int		px(t_cursor *head, t_stack *_throw, t_stack *_catch);
int		ft_simple_atoi(const char *str);
#endif
