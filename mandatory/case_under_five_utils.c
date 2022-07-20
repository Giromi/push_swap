/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_five_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:53:16 by minsuki2          #+#    #+#             */ /*   Updated: 2022/07/20 00:41:13 by minsuki2         ###   ########.fr       */ /*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_a_roswap(t_cursor *head, char **order, char priv, int n)
{
	int	i;

	i = 0;
	if ((priv != BIT_RA)
		&& !priv_check_swap(repeat_priv(head->cur_a, 2 + n), head->cnt_a - 3))
		while (i++ < n + 1)
			rrx(head, head->cur_a, order);
	else if ((priv != BIT_RRA)
		&& !priv_check_swap(repeat_next(head->cur_a, n), head->cnt_a - 3))
		while (i++ < n + 1)
			rx(head, head->cur_a, order);
	return (priv_check_swap(head->cur_a->priv, head->cnt_a - 3));
}

int	stack_is_a_rotate(t_cursor *head, char **order, char priv, int n)
{
	int		i;

	i = 0;
	if ((priv != BIT_RA)
		&& priv_check(repeat_priv(head->cur_a, 2 + n)) == SUCCESS)
		while (i++ < n + 1)
			rrx(head, head->cur_a, order);
	else if ((priv != BIT_RRA)
		&& priv_check(repeat_next(head->cur_a, n)) == SUCCESS)
		while (i++ < n + 1)
			rx(head, head->cur_a, order);
	return (priv_check(head->cur_a->priv));
}

int	priv_check(t_stack *now)
{
	t_stack	*first;

	first = now;
	while (now->priv != first)
	{
		if (now->tmp_idx - now->priv->tmp_idx != 1)
			return (ERROR);
		now = now->priv;
	}
	return (SUCCESS);
}

int	priv_check_limit(t_stack *now, t_stack *first, int delta)
{
	if (!now || !first)
		return (ERROR);
	while (now->priv != first)
	{
		if (now->tmp_idx - now->priv->tmp_idx != delta)
			return (ERROR);
		now = now->priv;
	}
	return (SUCCESS);
}

int	priv_check_swap(t_stack *now, int swap_cnt)
{
	t_stack	*first;
	int		i;

	i = 0;
	first = now;
	while (now->priv != first)
	{
		if (i >= swap_cnt
			&& (now->priv->tmp_idx == 0 && now->priv->priv->tmp_idx == 1))
			return (SUCCESS);
		else if (i < swap_cnt && now->tmp_idx - now->priv->tmp_idx != 1)
			return (ERROR);
		i++;
		now = now->priv;
	}
	return (ERROR);
}
