/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:23 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 15:28:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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
	int				tmp_idx;
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

typedef struct s_cnt
{
	int				pa;
	int				pb;
	int				ra;
	int				rb;
}	t_cnt;

char	*ft_strchr_null(const char *s, int c);
void	stack_head_set(t_cursor *head, t_stack *first);
char	ft_counteract(char *str, int *len, char add);
int		stack_pushidx(t_stack *_throw, t_stack *_catch);
t_stack	*repeat_next(t_stack *top, int n);
t_stack	*repeat_priv(t_stack *top, int n);
t_stack	*stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst, t_stack *new);
int		stack_lstadd_back(t_stack **lst, t_stack *new);
void	stack_lstfclean(t_cursor *head);
void	lst_clean(t_stack **lst);
char	sort_rotate_goal(t_cursor *head, char **order, char priv_command);
char	sx(t_cursor *head, t_stack *top);
char	rx(t_cursor *head, t_stack *top);
char	rrx(t_cursor *head, t_stack *top);
char	px(t_cursor *head, t_stack *_throw, t_stack *_catch);
int		case_check(t_cursor *head);
int		sort_swap(t_cursor *head, t_stack *top);
int		next_check(t_stack *now);
int		priv_check(t_stack *now);
char	sort_push_method(t_cursor *head);
int		priv_check_swap(t_stack *now, int swap_cnt);
int		wall_sort_two(t_cursor *head, char spot);
int		wall_check_stack(t_cursor *head, int n, char spot);
int		where_idx_n(t_cursor *head, int n, char spot);
int		next_check_nspot(t_cursor *head, int n, char spot);
void	stack_a_to_b(t_cursor *head, int offset, int n, int *flag);
int		ft_simple_atoi(const char *str);
#endif
