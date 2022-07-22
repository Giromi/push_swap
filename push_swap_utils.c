/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:22:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 21:16:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	head->order = (char *)malloc(sizeof(char));
	if (!head->order)
	{
		stack_lstfclean(head);
		exit(1);
	}
	ft_bzero(head->order, sizeof(char));
}

char	ft_counteract(char *str, int *len, char add)
{
	int	tmp;

	tmp = *len;
	if ((str[*len - 2] | add) == (BIT_RRA | BIT_RA))
		(*len) -= 2;
	else if ((str[*len - 2] | add) == (BIT_RRB | BIT_RB))
		(*len) -= 2;
	else if ((str[*len - 2] | add) == (char)(BIT_PA | BIT_PB))
		(*len) -= 2;
	else if (str[*len - 2] == BIT_SA && add == BIT_SA)
		(*len) -= 2;
	else if (str[*len - 2] == BIT_SB && add == BIT_SB)
		(*len) -= 2;
	if (tmp != *len)
		return (BIT_INT);
	return (add);
}

int	stack_pushidx(t_stack *_throw, t_stack *_catch)
{
	int		criterion_num;
	t_stack	*push;

	criterion_num = _throw->num;
	_throw->tmp_idx = 0;
	push = _throw;
	while (_throw || _catch)
	{
		if (_throw && _throw->num > criterion_num)
			_throw->tmp_idx--;
		if (_catch && _catch->num > criterion_num)
			_catch->tmp_idx++;
		else if (_catch && _catch->num < criterion_num)
			push->tmp_idx++;
		if (_throw)
			_throw = _throw->next;
		if (_catch)
			_catch = _catch->next;
	}
	return (SUCCESS);
}
