/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_five_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:53:16 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 14:50:31 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
