/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:40:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/20 13:57:00 by minsuki2         ###   ########.fr       */
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

int sort_swap(t_cursor *head, t_stack *top, char **order)
{
	if (!top || !top->next)
		return (ERROR);
	if (top->tmp_idx - top->next->tmp_idx == 1)
	{
		sx(head, top, order);
		return (SUCCESS);
	}
	if (((top->tmp_idx == 0 && top->next->tmp_idx == head->cnt_a - 1)
			&& next_check(top->next->next) == SUCCESS))
	{
		sx(head, top, order);
		return (SUCCESS);
	}
	return (ERROR);
}

char	sort_swap_b(t_cursor *head, char **order)
{
	if (head->cur_b && head->cur_b->next)
		if (head->cur_b->next->tmp_idx > head->cur_b->tmp_idx)
			return (sx(head, head->cur_b, order));
	return (BIT_INT);
}
