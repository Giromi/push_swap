/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:22:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/20 10:21:37 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_emergency(t_cursor *head, char *order)
{
	stack_lstfclean(head);
	free(order);
	exit(1);
}


void	*ft_charundo(char *s)
{
	char	*pt;
	int		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) - 1;
	if (size < 0)
		return (NULL);
	pt = (char *)malloc(sizeof(char) * size);
	pt[size - 1] = '\0';
	if (!pt)
		return (NULL);
	ft_strlcpy(pt, s, size);
	free(s);
	return (pt);
}

int ft_isminus(int c)
{
	return (c == '-');
}

int ft_issp(int c)
{
	return (c == ' ');
}

void full_clean(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	if (array)
		free(array);
	printf("Finished full_clean\n");
}

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len)
{
	size_t	dstsize;

	src_len = ft_strlen(src);
	dstsize = src_len + dst_len + 1;
	dst[dstsize - 1] = '\0';
	while (dstsize-- - 1 > dst_len)
		dst[dstsize - 1] = src[dstsize - dst_len - 1];
	return (dst_len + src_len);
}

size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize)
{
	if (dstsize > 0)
	{
		if (len + 1 < dstsize)
			dstsize = len + 1;
		dst[dstsize - 1] = '\0';
		while (dstsize-- - 1)
			dst[dstsize - 1] = src[dstsize - 1];
	}
	return (len);
}

char	*ft_strjoin_addsp(char const *s1, char const *s2)
{
	char	*pt;
	size_t	size;

	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size =  s1_len + s2_len + 2;
	pt = (char *)malloc(sizeof(char) * size);
	if (!pt)
		return (NULL);
	pt[size - 1] = ' ';
	ft_strlcpy_known(pt, s1, s1_len, size);
	ft_strlcat_known(pt, s1_len, s2, s2_len);
	return (pt);
}

char	*ft_strchr_null(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return ((char *)s + i);
}

t_stack *stack_lstnew(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->idx = 0;
	new->tmp_idx = 0;
	new->spot = '0';
	new->next = NULL;
	new->priv = NULL;
	return (new);
}


t_stack	*stack_lstlast(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	last = NULL;
	while (lst)
	{
		if (new && lst->num == new->num)
			return (NULL);
		if (new && lst->num > new->num)
			lst->idx++;
		else if (new && lst->num < new->num)
			new->idx++;
		if (!lst->next)
			last = lst;
		lst = lst->next;
	}
	return (last);
}

int stack_pushidx(t_stack *_throw, t_stack *_catch)
{
	int criterion_num;
	t_stack *push;

	criterion_num = _throw->num;
	_throw->tmp_idx = 0;
	push = _throw;
	while (_throw || _catch)
	{
		if (_throw && _throw->num > criterion_num)
			_throw->tmp_idx--;
		if (_catch && _catch->num > criterion_num)
			_catch->tmp_idx++;
		else if(_catch && _catch->num < criterion_num)
			push->tmp_idx++;
		if (_throw)
			_throw = _throw->next;
		if (_catch)
			_catch = _catch->next;
	}
	return (SUCCESS);
}

/* int stack_groupidx(t_stack *cur, int n) */
/* { */
	/* int		i; */
	/* int		j; */
	/* t_stack	*top; */

	/* if (!cur) */
		/* return (ERROR); */
	/* i = 0; */
	/* while (cur->next && i < n - 1) */
	/* { */
		/* cur->tmp_idx = 0; */
		/* top = cur; */
		/* j = 0; */
		/* while (top->next && j < n - 1) */
		/* { */
			/* if (cur->num > top->num) */
				/* cur->tmp_idx++; */
			/* top = top->next; */
		/* } */
		/* cur = cur->next; */
	/* } */
	/* return (SUCCESS); */
/* } */

int	stack_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return (ERROR);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = stack_lstlast(*lst, new);
		if (!tmp)
			return (ERROR);
		tmp->next = new;
		new->priv = tmp;
	}
	return (SUCCESS);
}

int	stack_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!lst || !new)
		return (ERROR);
	first = stack_lstnew(new->num);
	free(new);
	if (!*lst)
	{
		first->next = NULL;
		first->priv = NULL;
	}
	else
		first->next = *lst;
	*lst = first;
	return (SUCCESS);
}


void lst_clean(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

void	stack_lstfclean(t_cursor *head)
{
	if (!head)
		return ;
	lst_clean(&head->cur_a);
	lst_clean(&head->cur_b);
}

void stack_cut(t_stack **lst)
{
	if ((*lst))
	{
		(*lst)->priv = NULL;
		(*lst)->next = NULL;
	}
}

/* int	sa(t_cursor *head, char *result) */
/* { */
	/* t_stack	*tmp; */

	/* if (!head->cur_a || !head->cur_a->next) */
		/* return (ERROR); */
	/* tmp = head->cur_a->next->next; */
	/* if (head->cur_a->next->next) */
		/* head->cur_a->next->next->priv = head->cur_a; */
	/* head->cur_a->next->next = head->cur_a; */
	/* if (head->cur_a->priv != head->cur_a->next) */
		/* head->cur_a->next->priv = head->cur_a->priv; */
	/* head->cur_a->priv = head->cur_a->next; */
	/* head->cur_a->next = tmp; */
	/* head->cur_a = head->cur_a->priv; */
	/* return (ft_charjoin(&result, BIT_SA)); */
/* } */

/* int	sb(t_cursor *head, char **result) */
/* { */
	/* t_stack	*tmp; */

	/* if (!head->cur_b || !head->cur_b->next) */
		/* return (ERROR); */
	/* tmp = head->cur_b->next->next; */
	/* if (head->cur_b->next->next) */
		/* head->cur_b->next->next->priv = head->cur_b; */
	/* head->cur_b->next->next = head->cur_b; */
	/* if (head->cur_b->priv != head->cur_b->next) */
		/* head->cur_b->next->priv = head->cur_b->priv; */
	/* head->cur_b->priv = head->cur_b->next; */
	/* head->cur_b->next = tmp; */
	/* head->cur_b = head->cur_b->priv; */
	/* return (ft_charjoin(&result, BIT_SB)); */
/* } */



/* int	ss(t_cursor *head, char *result) */
/* { */
	/* result = sa(head, result); */
	/* return (sb(head, result)); */
/* } */

/* void	pa(t_cursor *head, char *result) */
/* { */
	/* t_stack *tmp; */

	/* if (!head->cur_b) */
		/* return (result); */
	/* stack_pushidx(head->cur_b, head->cur_a); */
	/* tmp = head->cur_b; */
	/* if (head->cur_b->next) */
	/* { */
		/* head->cur_b->next->priv = head->cur_b->priv; */
		/* head->cur_b = head->cur_b->next; */
	/* } */
	/* else */
		/* head->cur_b = NULL;		// if) head->cur_a empty */
	/* tmp->next = head->cur_a; */
	/* tmp->priv = tmp; */
	/* if (head->cur_a) */
	/* { */
		/* tmp->priv = head->cur_a->priv; */
		/* head->cur_a->priv = tmp; */
	/* } */
	/* head->cur_a = tmp; */
	/* head->cnt_a++; */
	/* head->cnt_b--; */
	/* return (ft_charjoin(&result, BIT_PA)); */
/* } */


/* void	pb(t_cursor *head, char *result) */
/* { */
	/* t_stack *tmp; */

	/* if (!head->cur_a) */
		/* return (NULL); */
	/* stack_pushidx(head->cur_a, head->cur_b); */
	/* tmp = head->cur_a; */
	/* if (head->cur_a->next) */
	/* { */
		/* head->cur_a->next->priv = head->cur_a->priv; */
		/* head->cur_a = head->cur_a->next; */
	/* } */
	/* else */
		/* head->cur_a = NULL;		// if) head->cur_a empty */
	/* tmp->next = head->cur_b; */
	/* tmp->priv = tmp; */
	/* if (head->cnt_a-- && ++head->cnt_b && head->cur_b) */
	/* { */
		/* tmp->priv = head->cur_b->priv; */
		/* head->cur_b->priv = tmp; */
	/* } */
	/* head->cur_b = tmp; */
	/* head->cur_b->spot = '1'; */
	/* return (ft_charjoin(result, BIT_PB)); */
/* } */



/* vid	ra(t_stack **top, char *result) */
/* { */
	/* if (!head->cur_a || !head->cur_a->next) */
		/* return (NULL); */
	/* head->cur_a->priv->next = head->cur_a; */
	/* head->cur_a = head->cur_a->next; */
	/* head->cur_a->priv->next = NULL; */
	/* return (ft_charjoin(&result, BIT_RA)); */
/* } */


/* void	ra(t_cursor *head, char **result) */
/* { */
	/* if (!head->cur_a || !head->cur_a->next) */
		/* return (result); */
	/* head->cur_a->priv->next = head->cur_a; */
	/* head->cur_a = head->cur_a->next; */
	/* head->cur_a->priv->next = NULL; */
	/* return (ft_charjoin(&result, BIT_RB)); */
/* } */

/* void	rb(t_cursor *head, char **result) */
/* { */
	/* if (!head->cur_b || !head->cur_b->next) */
		/* return (result); */
	/* head->cur_b->priv->next = head->cur_b; */
	/* head->cur_b = head->cur_b->next; */
	/* head->cur_b->priv->next = NULL; */
	/* ft_charjoin(&result, BIT_RB); */
/* } */

/* void	rr(t_cursor *head, char **result) */
/* { */
	/* ra(head, result); */
	/* rb(head, result): */
/* } */

/* void	rra(t_cursor *head, char **result) */
/* { */
	/* if (!head->cur_a || head->cur_a->priv == head->cur_a) */
		/* return (result); */
	/* head->cur_a->priv->next = head->cur_a; */
	/* head->cur_a = head->cur_a->priv; */
	/* head->cur_a->priv->next = NULL; */
	/* return (ft_charjoin(result, BIT_RRA)); */
/* } */


/* void	rrb(t_cursor *head, char *result) */
/* { */
	/* if (!head->cur_b || head->cur_b->priv == head->cur_b) */
		/* return (result); */
	/* head->cur_b->priv->next = head->cur_b; */
	/* head->cur_b = head->cur_b->priv; */
	/* head->cur_b->priv->next = NULL; */
	/* return (ft_charjoin(result, BIT_RRB)); */
/* } */


/* void	rrr(t_cursor *head, char **result) */
/* { */
	/* rra(head, result); */
	/* rrb(head, result); */
/* } */

void whether_a_b(char c)
{
	char	set_a;
	char	set_b;

	set_a = (char)(BIT_PA | BIT_SA | BIT_RA | BIT_RRA);
	set_b = (char)(BIT_PB | BIT_SB | BIT_RB | BIT_RRB);

	if (c & set_a)
		write(1, "a", 1);
	else if (c & set_b)
		write(1, "b", 1);
}

/* int ft_charnstr(const char *str, int *n, char c) */
/* { */
	/* int	offset; */

	/* offset = 0; */
	/* while (n-- && *str) */
	/* { */
		/* if (*str ==) */


		/* str++; */
	/* } */
	/* return (offset); */
/* } */

/* void	*ft_charundo(char *s) */
/* { */
	/* char	*pt; */
	/* int		size; */

	/* if (!s) */
		/* return (NULL); */
	/* size = ft_strlen(s) - 1; */
	/* if (size < 0) */
		/* return (NULL); */
	/* pt = (char *)malloc(sizeof(char) * size); */
	/* pt[size - 1] = '\0'; */
	/* if (!pt) */
		/* return (NULL); */
	/* ft_strlcpy(pt, s, size); */
	/* free(s); */
	/* return (pt); */
/* } */

/* int	order_compress(char *result) */
/* { */
	/* ra  */


/* } */

int	order_print(char *result)
{
	int	i;
	int old_i;
	int cnt;

	cnt = 0;
	if (!result)
		return (cnt);
	i = 0;
	while (result[i++])
	{
		old_i = i;
		/* if (ft_charnstr(result + i - 1, ea_a, ea_b, (BIT_RA | BIT_RB))) */
		/* { */
			/* write(1, "rr", 2); */
			/* i += ea_a; */
		// 다음 문자열이 확정 되어야 출력
		//
		/* } */
		if (result[i - 1] & (BIT_PA | BIT_PB))
			write(1, "p", 1);
		else if ((result[i - 1] | result[i]) == (BIT_SA | BIT_SB) && ++i)
			write(1, "ss", 2);
		else if ((result[i - 1] | result[i]) == (BIT_RA | BIT_RB) && ++i)
			write(1, "rr", 2);
		else if ((result[i - 1] | result[i]) == (BIT_RRA | BIT_RRB) && ++i)		//	두개 더하면 - overflow 발생해서는 안됨.
			write(1, "rrr", 3);													//	=> (char)쓰면 80자 넘어감
		else if (result[i - 1] & (BIT_SA | BIT_SB))
			write(1, "s", 1);
		else if (result[i - 1] & (BIT_RA | BIT_RB))
			write(1, "r", 1);
		else if (result[i - 1] & (BIT_RRA | BIT_RRB))
			write(1, "rr", 2);
		if (old_i == i)
			whether_a_b(result[i - 1]);
		write(1, "\n", 1);
		cnt++;
	}
	return (cnt);
}

int stack_circle(t_stack **lst)
{
	int		max_idx;
	t_stack	*tmp;
	t_stack	*last;

	max_idx = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->tmp_idx = tmp->idx;
		/* if (delta) */
			/* *delta[i - 1] = tmp->next->idx - tmp->idx; */
		if (tmp->idx > max_idx)
			max_idx = tmp->idx;
		if (!tmp->next)
			last = tmp;
		tmp = tmp->next;
	}
	if (!(*lst)->priv)
		(*lst)->priv = last;
	return (max_idx + 1);
}

void	stack_headset(t_cursor *head, t_stack *first)
{
	if (!head || !first)
		return ;
	head->cur_a = first;
	head->cur_b = NULL;
	head->cnt_a = stack_circle(&first);
	head->cnt_b = 0;
}

char	ft_counteract(char *str, int *len, char add)
{
	if (((str[*len - 2] | add) == (BIT_RRA | BIT_RA))
			|| ((str[*len - 2] | add) == (BIT_RRB | BIT_RB))
			|| ((str[*len - 2] | add) == (char)(BIT_PA | BIT_PB))
			|| (str[*len - 2] == BIT_SA && add == BIT_SA)
			|| (str[*len - 2] == BIT_SB && add == BIT_SB))
	{
		(*len) -= 2;
		return (BIT_INT);
	}
	return (add);
}

