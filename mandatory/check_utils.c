/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:39:35 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 14:46:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_check_nspot(t_cursor *head, int n, char spot)
{
	t_stack *now;

	now = head->cur_a;
	if (spot == '2')
		now = head->cur_b;
	if (!now)
		return (ERROR);
	while (now->next && n-- - 1)
	{
		if (spot == '0' && now->next->idx - now->idx != 1)
			return (ERROR);
		if (spot == '2' && now->idx - now->next->idx != 1)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}

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
