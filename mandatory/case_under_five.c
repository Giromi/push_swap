/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:08:24 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 13:23:13 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_rotate_roswap(t_cursor *head, char priv_cm)
{
	int		n;
	int		check;

	check = ERROR;
	if (priv_cm != BIT_SA && sort_swap(head, head->cur_a) == SUCCESS)
	{
		priv_cm = BIT_SA;
		sort_swap_b(head);
	}
	n = 0;
	while (n < head->cnt_a / 2 && check == ERROR)
		check = stack_is_a_rotate(head, priv_cm, n++);
	n = 0;
	while (n < head->cnt_a / 2 && check == ERROR)
		check = stack_is_a_roswap(head, priv_cm, n++);
	if (check == SUCCESS)
	{
		sort_swap(head, head->cur_a);
		return (SUCCESS);
	}
	if (priv_cm & BIT_SA)
		sx(head, head->cur_a);
	return (ERROR);
}

static int	sort_try_method_four(t_cursor *head)
{
	if (head->cur_a->tmp_idx != 0 || head->cur_a->next->tmp_idx != 3)
	{
		rx(head, head->cur_a);
		if (sort_rotate_roswap(head, BIT_RA) == SUCCESS)
			return (SUCCESS);
		rrx(head, head->cur_a);
	}
	rrx(head, head->cur_a);
	if (sort_rotate_roswap(head, BIT_RRA) == SUCCESS)
		return (SUCCESS);
	rx(head, head->cur_a);
	if (head->cur_a->tmp_idx >= 2)
	{
		rx(head, head->cur_a);
		rx(head, head->cur_a);
		if (sort_rotate_roswap(head, BIT_RA) == SUCCESS)
			return (SUCCESS);
		rrx(head, head->cur_a);
		rrx(head, head->cur_a);
	}
	return (ERROR);
}

static char	sort_push_method(t_cursor *head)
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

int	case_check(t_cursor *head)
{
	int	check;

	check = priv_check(head->cur_a->priv);
	if (check == ERROR && head->cnt_a <= 2)
		check = sort_swap(head, head->cur_a);
	if (check == ERROR && head->cnt_a >= 3)
		check = sort_rotate_roswap(head, BIT_INT);
	if (check == ERROR && head->cnt_a == 4)
		check = sort_try_method_four(head);
	if (check == ERROR && head->cnt_a >= 4 && head->cnt_a < 6)
		check = sort_push_method(head);
	return (check);
}
