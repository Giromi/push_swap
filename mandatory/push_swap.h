/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:23 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/07 21:46:33 by minsuki2         ###   ########.fr       */
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
# define BIT_SA		0B00000001
# define BIT_SB		0B00000010
# define BIT_RA		0B00000100
# define BIT_RB		0B00001000
# define BIT_RRA	0B00010000
# define BIT_RRB	0B00100000
# define BIT_PA		0B01000000
# define BIT_PB		0B10000000
# define VAL_INT_MIN	2147483648
# define VAL_INT_MAX	2147483647

typedef struct s_stack
{
	int num;
	int idx;
	struct s_stack *next;
	struct s_stack *priv;
} t_stack;

typedef struct s_cursor
{
	t_stack *cur_a;
	t_stack *cur_b;
} t_cursor;

size_t	ft_strlen(const char *s);
int		ft_isspace(int);
void	*ft_charundo(char *s);
int		ft_isminus(int c);
int		ft_issp(int c);
void	full_clean(char **array);
int		stack_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst, int check);
void	lst_clean(t_stack **lst);
void	stack_lstfclean(t_cursor *head);
char	*ft_strchr_null(const char *s, int c);

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len);
size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize);
char	*ft_strjoin_addsp(char const *s1, char const *s2);
void	stack_circle(t_stack **lst);
char	*pa(t_cursor *head, char *result);
char	*pb(t_cursor *head, char *result);
char	*sa(t_cursor *head, char *result);
char	*sb(t_cursor *head, char *result);
char	*ss(t_cursor *head, char *result);
char	*ra(t_cursor *head, char *result);
char	*rb(t_cursor *head, char *result);
char	*rr(t_cursor *head, char *result);
char	*rra(t_cursor *head, char *result);
char	*rrb(t_cursor *head, char *result);
char	*rrr(t_cursor *head, char *result);
void	order_print(char *result);
int		ft_simple_atoi(const char *str);

#endif
