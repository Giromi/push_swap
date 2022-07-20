/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:08:24 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/19 18:34:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_rotate_roswap(t_cursor *head, char **order, char priv_cm)
{
	int		n;
	int		check;

	check = ERROR;
	if (priv_cm != BIT_SA && sort_swap(head, head->cur_a, order) == SUCCESS)
	{
		priv_cm = BIT_SA;
		sort_swap_b(head, order);
	}
	n = 0;
	while (n < head->cnt_a / 2 && check == ERROR)
		check = stack_is_a_rotate(head, order, priv_cm, n++);
	n = 0;
	while (n < head->cnt_a / 2 && check == ERROR)
		check = stack_is_a_roswap(head, order, priv_cm, n++);
	if (check == SUCCESS)
	{
		sort_swap(head, head->cur_a, order);
		return (SUCCESS);
	}
	if (priv_cm & BIT_SA)
		sx(head, head->cur_a, order);
	return (ERROR);
}

static int	sort_try_method_four(t_cursor *head, char **order)
{
	if (head->cur_a->tmp_idx != 0 || head->cur_a->next->tmp_idx != 3)
	{
		rx(head, head->cur_a, order);
		if (sort_rotate_roswap(head, order, BIT_RA) == SUCCESS)
			return (SUCCESS);
		rrx(head, head->cur_a, order);
	}
	rrx(head, head->cur_a, order);
	if (sort_rotate_roswap(head, order, BIT_RRA) == SUCCESS)
		return (SUCCESS);
	rx(head, head->cur_a, order);
	if (head->cur_a->tmp_idx >= 2)
	{
		rx(head, head->cur_a, order);
		rx(head, head->cur_a, order);
		if (sort_rotate_roswap(head, order, BIT_RA) == SUCCESS)
			return (SUCCESS);
		rrx(head, head->cur_a, order);
		rrx(head, head->cur_a, order);
	}
	return (ERROR);
}

static char	sort_push_method(t_cursor *head, char **order)
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
			rx(head, head->cur_a, order);
	else if (i > j)
		while (j--)
			rrx(head, head->cur_a, order);
	px(head, head->cur_a, head->cur_b, order);
	check = case_check(head, order);
	px(head, head->cur_b, head->cur_a, order);
	sort_swap(head, head->cur_a, order);
	return (check);
}

int	case_check(t_cursor *head, char **order)
{
	int	check;

	check = priv_check(head->cur_a->priv);
	if (check == ERROR && head->cnt_a <= 2)
		check = sort_swap(head, head->cur_a, order);
	if (check == ERROR && head->cnt_a >= 3)
		check = sort_rotate_roswap(head, order, BIT_INT);
	if (check == ERROR && head->cnt_a == 4)
		check = sort_try_method_four(head, order);
	if (check == ERROR && head->cnt_a >= 4 && head->cnt_a < 6)
		check = sort_push_method(head, order);
	return (check);
}
