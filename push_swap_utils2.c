/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:53:16 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 15:16:07 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*repeat_next(t_stack *top, int n)
{
	while (top && n--)
		top = top->next;
	return (top);
}

t_stack	*repeat_priv(t_stack *top, int n)
{
	while (top && n--)
		top = top->priv;
	return (top);
}

char	sort_push_method(t_cursor *head)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (repeat_next(head->cur_a, i)->tmp_idx > 1)
		i++;
	while (repeat_priv(head->cur_a, j)->tmp_idx > 1)
		j++;
	if (i <= j)
		while (i--)
			rx(head, head->cur_a);
	else if (i > j)
		while (j--)
			rrx(head, head->cur_a);
	px(head, head->cur_a, head->cur_b);
	check = case_check(head);
	px(head, head->cur_b, head->cur_a);
	sort_swap(head, head->cur_a);
	return (check);
}

int sort_swap(t_cursor *head, t_stack *top)
{
	if (!top || !top->next)
		return (ERROR);
	if (top->tmp_idx - top->next->tmp_idx == 1)
	{
		sx(head, top);
		return (SUCCESS);
	}
	if (((top->tmp_idx == 0 && top->next->tmp_idx == head->cnt_a - 1)
			&& next_check(top->next->next) == SUCCESS))
	{
		sx(head, top);
		return (SUCCESS);
	}
	return (ERROR);
}

int where_idx_n(t_cursor *head, int n, char spot)
{
	int		find_idx;
	t_stack *tmp;

	tmp = head->cur_a;
	if (spot == '2')
		tmp = head->cur_b;
	if (!tmp)
		return (ERROR);
	find_idx = tmp->idx;
	while (tmp && n--)
	{
		if (spot == '0' && tmp->idx < find_idx)
			find_idx = tmp->idx;
		else if (spot == '2' && tmp->idx > find_idx)
			find_idx = tmp->idx;
		tmp = tmp->next;
	}
	return (find_idx);
}
