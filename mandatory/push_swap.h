/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:23 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/10 17:46:24 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
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
	int		num;
	int		tmp_idx;
	int		idx;
	char	spot;
	struct s_stack *next;
	struct s_stack *priv;
} t_stack;

typedef struct s_cursor
{
	t_stack *cur_a;
	int	cnt_a;
	t_stack *cur_b;
	int	cnt_b;
	char *order;
} t_cursor;

typedef struct s_cnt
{
	int	pa;
	int	pb;
	int ra;
	int rb;
} t_cnt;

void	ft_emergency(t_cursor *head, char *order);
size_t	ft_strlen(const char *s);
int		ft_isspace(int);
void	*ft_charundo(char *s);
int		ft_isminus(int c);
int		ft_issp(int c);
void	full_clean(char **array);
int		stack_circle(t_stack **lst);
int		stack_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst, t_stack *new);
void	lst_clean(t_stack **lst);
void	stack_lstfclean(t_cursor *head);
char	*ft_strchr_null(const char *s, int c);

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len);
size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize);
char	*ft_strjoin_addsp(char const *s1, char const *s2);
int		order_print(char *result);
int		ft_simple_atoi(const char *str);
void	stack_headset(t_cursor *head, t_stack *first);
int	stack_pushidx(t_stack *_throw, t_stack *_catch);
char *quick_sort(t_cursor *head, char *order);
char	sort_rotate_goal(t_cursor *head, char **order, char priv_command);

char	sx(t_cursor *head, t_stack *top);
char	rx(t_cursor *head, t_stack *top);
char	rrx(t_cursor *head, t_stack *top);
char	px(t_cursor *head, t_stack *_throw, t_stack *_catch);
void	stack_a_to_b(t_cursor *head, int offset, int n, int *flag);

// void	pa(t_cursor *head, char *result);
// void	pb(t_cursor *head, char *result);
// void	sa(t_cursor *head, char *result);
// void	sb(t_cursor *head, char *result);
// void	ss(t_cursor *head, char *result);
// void	ra(t_cursor *head, char *result);
// void	rb(t_cursor *head, char *result);
// void	rr(t_cursor *head, char *result);
// void	rra(t_cursor *head, char *result);
// void	rrb(t_cursor *head, char *result);
// void	rrr(t_cursor *head, char *result);
int debug_sort_check(t_cursor *head);
void debug_print(t_cursor *head, int choice);
char	ft_counteract(char *str, int *len, char add);

t_stack	*repeat_next(t_stack *top, int n);
t_stack	*repeat_priv(t_stack *top, int n);
int	next_check_nspot(t_cursor *head, int n, char spot);
int	next_check(t_stack *now);
int priv_check(t_stack *now);
int	priv_check_limit(t_stack *now, t_stack *first, int delta);
int priv_check_swap(t_stack *now, int swap_cnt);
int sort_swap(t_cursor *head, t_stack *top);
char	sort_swap_b(t_cursor *head);

int	stack_is_a_rotate(t_cursor *head, char priv, int n);
int	stack_is_a_roswap(t_cursor *head, char priv, int n);
int	case_check(t_cursor *head);

void	recursive_sort(t_cursor *head, char **order);
int wall_check_stack(t_cursor *head, int n, char spot);
#endif

