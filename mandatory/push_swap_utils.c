/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:22:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 13:16:27 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_lstfclean(t_cursor *head)
{
	if (!head)
		return ;
	lst_clean(&head->cur_a);
	lst_clean(&head->cur_b);
	free(head->order);
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


void stack_cut(t_stack **lst)
{
	if ((*lst))
	{
		(*lst)->priv = NULL;
		(*lst)->next = NULL;
	}
}

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

int	order_print(char *result)
{
	int	i;
	int old_i;
	int cnt;

	cnt = ft_strlen(result);
	cnt = 0;
	if (!result)
		return (cnt);
	i = 0;
	while (result[i++])
	{
		old_i = i;
		if ((result[i - 1] | result[i]) == (BIT_SA | BIT_SB) && ++i)
			write(1, "ss", 2);
		else if ((result[i - 1] | result[i]) == (BIT_RA | BIT_RB) && ++i)
			write(1, "rr", 2);
		else if ((result[i - 1] | result[i]) == (BIT_RRA | BIT_RRB) && ++i)		//	두개 더하면 - overflow 발생해서는 안됨.
			write(1, "rrr", 3);													//	=> (char)쓰면 80자 넘어감
		else if (result[i - 1] & (BIT_PA | BIT_PB))
			write(1, "p", 1);
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
	head->order = (char *)malloc(sizeof(char));
	if (!head->order)
	{
		stack_lstfclean(head);
		exit(1);
	}
	ft_bzero(head->order, sizeof(char));
}


