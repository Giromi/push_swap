/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:04:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/20 17:43:38 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wall_sort_two(t_cursor *head, char **order, char spot)
{
	if (spot == '0')
	{
		if (!head->cur_a || !head->cur_a->next)
			return ;
		if (head->cur_a->idx > head->cur_a->next->idx)
			sx(head, head->cur_a, order);
	}
	if (spot == '2')
	{
		if (!head->cur_b || !head->cur_b->next)
			return ;
		if (head->cur_b->idx < head->cur_b->next->idx)
			sx(head, head->cur_b, order);
	}
}

void wall_sort_three(t_cursor *head, char **order, char spot)
{
	if (spot == '0')
	{
		px(head, head->cur_a, head->cur_b, order);
		wall_sort_two(head, order, spot);
		px(head, head->cur_b, head->cur_a, order);
		wall_sort_two(head, order, spot);
	}
	if (spot == '2')
	{
		px(head, head->cur_b, head->cur_a, order);
		wall_sort_two(head, order, spot);
		px(head, head->cur_a, head->cur_b, order);
		wall_sort_two(head, order, spot);
	}
}
/* void wall_sort_four(t_cursor *head, int pv, char **order) */
/* { */
	/* int	i; */


	/* stack_groupidx(head->cur_a, 4); */
	/* i = 0; */
	/* while (i++ < 4) */
	/* { */
		/* if (head->cur_a->tmp_idx < pv) */
			/* px(head, head->cur_a, head->cur_b, order); */
		/* else */
			/* rx(head, head->cur_a, order); */
	/* } */
	/* while (i-- > 2) */
		/* rrx(head, head->cur_a, order); */
	/* wall_sort_two(head, order, 0); */
	/* wall_sort_two(head, order, 1); */
	/* while (i--) */
		/* px(head, head->cur_a, head->cur_b, order); */
/* } */
int	next_check(t_stack *now)
{
	if (!now)
		return (ERROR);
	while (now->next)
	{
		if (now->next->tmp_idx - now->tmp_idx != 1)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}

int	next_check_nspot(t_cursor *head, int n, char spot)
{
	t_stack *now;

	if (spot == '0' && head->cur_a)
		now = head->cur_a;
	if (spot == '2' && head->cur_b)
		now = head->cur_b;
	if (!now)
		return (ERROR);
	while (now->next && n-- - 1)
	{
		if (spot == '0' &&now->next->tmp_idx - now->tmp_idx != 1)
			return (ERROR);
		if (spot == '2' && now->tmp_idx - now->next->tmp_idx != 1)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}

int wall_check_stack(t_cursor *head, char **order, int n, char spot)
{
	/* int	pv; */

	/* pv = n / 2; */
	/* check = priv_check_limit(repeat_next(head->cur_b, n - 1), head->cur_a, -1); */
	if (next_check_nspot(head, n, spot) == SUCCESS)
		return (SUCCESS);
	if (n >= 2)
		wall_sort_two(head, order, spot);
	if (n == 3)
		wall_sort_three(head, order, spot);
	/* if (check == ERROR && n == 4) */
		/* wall_sort_four(head, pv, order); */
	/* if (check == ERROR && n == 5) */
		/* wall_sort_four(head, n, order); */
	return (SUCCESS);
}
