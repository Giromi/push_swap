/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:12:59 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 19:34:04 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	ft_charjoin_myself(t_cursor *head, char c)
{
	char	*pt;
	int		len;

	if (!head->order || !c)
		return (BIT_INT);
	len = ft_strlen(head->order) + 1;
	if (len > 1)
		c = ft_counteract(head->order, &len, c);
	pt = malloc(sizeof(char) * (len + 1));
	if (!pt)
	{
		stack_lstfclean(head);
		exit(1);
	}
	ft_strlcpy(pt, head->order, len + 1);
	if (c != BIT_INT && len > 0)
		pt[len - 1] = c;
	pt[len] = BIT_INT;
	free(head->order);
	head->order = pt;
	return (c);
}

char	sx(t_cursor *head, t_stack *top)
{
	int		backup_int;
	char	backup_char;

	if (!top || !top->next)
		return (BIT_INT);
	backup_int = top->next->idx;
	top->next->idx = top->idx;
	top->idx = backup_int;
	backup_int = top->next->num;
	top->next->num = top->num;
	top->num = backup_int;
	backup_char = top->next->spot;
	top->next->spot = top->spot;
	top->spot = backup_char;
	backup_int = top->next->tmp_idx;
	top->next->tmp_idx = top->tmp_idx;
	top->tmp_idx = backup_int;
	if (top->spot > '1')
		return (ft_charjoin_myself(head, BIT_SB));
	return (ft_charjoin_myself(head, BIT_SA));
}

char	rx(t_cursor *head, t_stack *top)
{
	char	bit;

	if (!top || !top->next)
	{
		if (top)
			top->spot += (top->spot % 2 == 0);
		return (BIT_INT);
	}
	top->priv->next = top;
	bit = BIT_RB;
	if (top->spot <= '1' )
	{
		bit = BIT_RA;
		head->cur_a = top->next;
	}
	else if (top->spot > '1')
		head->cur_b = top->next;
	top->spot += (top->spot % 2 == 0);
	top->next = NULL;
	return (ft_charjoin_myself(head, bit));
}

char	rrx(t_cursor *head, t_stack *top)
{
	char	bit;

	if (!top || !top->next)
	{
		if (top)
			top->spot -= (top->spot % 2 != 0);
		return (BIT_INT);
	}
	top->priv->next = top;
	bit = BIT_RRB;
	if (top->priv->spot <= '1')
	{
		bit = BIT_RRA;
		head->cur_a = top->priv;
	}
	else if (top->priv->spot > '1')
		head->cur_b = top->priv;
	top->priv->spot -= (top->priv->spot % 2 != 0);
	top->priv->priv->next = NULL;
	return (ft_charjoin_myself(head, bit));
}

char	px(t_cursor *head, t_stack *_throw, t_stack *_catch)
{
	if (!_throw || stack_pushidx(_throw, _catch))
		return (BIT_INT);
	if (_throw->next)
		_throw->next->priv = _throw->priv;
	_throw->priv = _throw;
	if (_catch)
	{
		_throw->priv = _catch->priv;
		_catch->priv = _throw;
	}
	head->cur_a = _throw->next;
	head->cur_b = _throw;
	if ((_throw->spot > '1') && ++head->cnt_a && head->cnt_b--)
	{
		head->cur_b = _throw->next;
		head->cur_a = _throw;
	}
	_throw->next = _catch;
	if ((_throw->spot <= '1') && head->cnt_a-- && ++head->cnt_b)
	{
		_throw->spot = '2';
		return (ft_charjoin_myself(head, BIT_PB));
	}
	_throw->spot = '0';
	return (ft_charjoin_myself(head, BIT_PA));
}
