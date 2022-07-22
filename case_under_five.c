/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:08:24 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 21:15:17 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_is_a_roswap(t_cursor *head, char priv, int n)
{
	int	i;

	i = 0;
	if ((priv != BIT_RA)
		&& !priv_check_swap(repeat_priv(head->cur_a, 2 + n), head->cnt_a - 3))
		while (i++ < n + 1)
			rrx(head, head->cur_a);
	else if ((priv != BIT_RRA)
		&& !priv_check_swap(repeat_next(head->cur_a, n), head->cnt_a - 3))
		while (i++ < n + 1)
			rx(head, head->cur_a);
	return (priv_check_swap(head->cur_a->priv, head->cnt_a - 3));
}

static int	stack_is_a_rotate(t_cursor *head, char priv, int n)
{
	int		i;

	i = 0;
	if ((priv != BIT_RA)
		&& priv_check(repeat_priv(head->cur_a, 2 + n)) == SUCCESS)
		while (i++ < n + 1)
			rrx(head, head->cur_a);
	else if ((priv != BIT_RRA)
		&& priv_check(repeat_next(head->cur_a, n)) == SUCCESS)
		while (i++ < n + 1)
			rx(head, head->cur_a);
	return (priv_check(head->cur_a->priv));
}

static int	sort_rotate_roswap(t_cursor *head, char priv_cm)
{
	int		n;
	int		check;

	check = ERROR;
	if (priv_cm != BIT_SA && sort_swap(head, head->cur_a) == SUCCESS)
	{
		priv_cm = BIT_SA;
		wall_sort_two(head, '2');
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
