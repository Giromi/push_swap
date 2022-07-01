/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:16:28 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/01 05:56:33 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/* t_stack	*ft_lstlast(t_stack *lst) */
/* { */
	/* if (!lst) */
		/* return (NULL); */
	/* while (lst->next) */
		/* lst = lst->next; */
	/* return (lst); */
/* } */

/* void	stack_lstadd_back(t_stack **lst, t_stack *new) */
/* { */
	/* t_stact	*tmp; */

	/* if (!lst || !new) */
		/* return ; */
	/* if (!*lst) */
		/* *lst = new; */
	/* else */
	/* { */
		/* tmp = stack_lstlast(*lst); */
		/* tmp->next = new; */
	/* } */
/* } */

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
	new->next = NULL;
	new->priv = NULL;
	return (new);
}


t_stack	*stack_lstlast(t_stack *lst, int check)
{
	t_stack	*first;

	if (!lst || (check && lst->num == check))
		return (NULL);
	if (check && lst->num > check)
		lst->idx++;
	while (lst->next)
	{
		if (check && lst->next->num == check)
			return (NULL);
		if (check && lst->next->num > check)
			lst->next->idx++;
		lst = lst->next;
	}
	return (lst);
}

void stack_circle(t_stack **lst)
{
	t_stack	*last;

	last = stack_lstlast(*lst, '\0');
	(*lst)->priv = last;
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
		tmp = stack_lstlast(*lst, new->num);
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
	if (head)
		free(head);
}

void stack_cut(t_stack **lst)
{
	if ((*lst))
	{
		(*lst)->priv = NULL;
		(*lst)->next = NULL;
	}
}

void sa(t_cursor *head)
{
	t_stack	*tmp;

	if (!head->cur_a || !head->cur_a->next)
		return ;
	head->cur_a->next->priv = head->cur_a->priv;
	head->cur_a->priv = head->cur_a->next;
	head->cur_a->next->next->priv = head->cur_a;
	head->cur_a->next = head->cur_a->next->next;
	head->cur_a->priv->next = head->cur_a;
	head->cur_a = head->cur_a->priv;
}

void pb(t_cursor *head)
{
	t_stack *tmp;

	if (!head->cur_a)
		return ;
	tmp = head->cur_a;
	if (head->cur_a->next)
	{
		head->cur_a->next->priv = head->cur_a->priv;
		head->cur_a = head->cur_a->next;
	}
	else
		head->cur_a = NULL;		// if) head->cur_a empty
	tmp->next = head->cur_b;
	tmp->priv = tmp;
	if (head->cur_b)
		tmp->priv = head->cur_b->priv;
	head->cur_b = tmp;
}

void pa(t_cursor *head)
{
	t_stack *tmp;

	head->cur_b->priv->next = head->cur_b->next;
	head->cur_b->next->priv = head->cur_b->priv;
	tmp = head->cur_b->next;
	head->cur_b->next = head->cur_a;
	head->cur_b->priv = NULL;
	head->cur_a = head->cur_b;
	head->cur_b = tmp;
}

void ra(t_cursor *head)
{
	if (!head->cur_a || !head->cur_a->next)
		return ;
	head->cur_a->priv->next = head->cur_a;
	head->cur_a = head->cur_a->next;
	head->cur_a->priv->next = NULL;
}

void rb(t_cursor *head)
{
	if (!head->cur_b || !head->cur_b->next)
		return ;
	head->cur_b->priv->next = head->cur_b;
	head->cur_b = head->cur_b->next;
	head->cur_b->priv->next = NULL;
}

void rra(t_cursor *head)
{
	if (!head->cur_a || head->cur_a->priv == head->cur_a)
		return ;
	head->cur_a->priv->next = head->cur_a;
	head->cur_a = head->cur_a->priv;
	head->cur_a->priv->next = NULL;
}


void rrb(t_cursor *head)
{
	if (!head->cur_b || head->cur_b->priv == head->cur_b)
		return ;
	head->cur_b->priv->next = head->cur_b;
	head->cur_b = head->cur_b->priv;
	head->cur_b->priv->next = NULL;
}

void rr(t_cursor *head)
{
	ra(head);
	rb(head);
}

void rrr(t_cursor *head)
{
	rra(head);
	rrb(head);
}
