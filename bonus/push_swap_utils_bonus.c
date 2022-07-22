/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:41 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 18:31:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* static	char	ft_charjoin_myself(t_cursor *head, char c) */
/* { */
	/* char	*pt; */
	/* int		len; */

	/* if (!head->order || !c) */
		/* return (BIT_INT); */
	/* len = ft_strlen(head->order) + 1; */
	/* if (len > 1) */
		/* c = ft_counteract(head->order, &len, c); */
	/* pt = malloc(sizeof(char) * (len + 1)); */
	/* if (!pt) */
	/* { */
		/* stack_lstfclean(head); */
		/* exit(1); */
	/* } */
	/* ft_strlcpy(pt, head->order, len + 1); */
	/* if (c != BIT_INT && len > 0) */
		/* pt[len - 1] = c; */
	/* pt[len] = '\0'; */
	/* free(head->order); */
	/* head->order = pt; */
	/* return (c); */
/* } */

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


static int	stack_circle(t_stack **lst)
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

void	stack_head_set(t_cursor *head, t_stack *first)
{
	if (!head || !first)
		return ;
	head->cur_a = first;
	head->cur_b = NULL;
	head->cnt_a = stack_circle(&first);
	head->cnt_b = 0;
	head->order = NULL;
}

int debug_sort_check(t_cursor *head)
{
	t_stack	*lst;

	if (head->cur_b)
		return (ERROR);
	lst = head->cur_a;
	while (lst->next)
	{
		if (lst->idx > lst->next->idx)
			return (ERROR);
		lst = lst->next;
	}
	return (SUCCESS);
}
