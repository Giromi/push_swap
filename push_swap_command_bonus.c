/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:12:59 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 21:54:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr_null(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return ((char *)s + i);
}

int	sx(t_stack *top)
{
	int		backup_int;
	char	backup_char;

	if (!top || !top->next)
		return (SUCCESS);
	backup_int = top->next->idx;
	top->next->idx = top->idx;
	top->idx = backup_int;
	backup_int = top->next->num;
	top->next->num = top->num;
	top->num = backup_int;
	backup_char = top->next->spot;
	top->next->spot = top->spot;
	top->spot = backup_char;
	return (SUCCESS);
}

int	rx(t_cursor *head, t_stack *top)
{
	if (!top || !top->next)
	{
		if (top)
			top->spot += (top->spot % 2 == 0);
		return (SUCCESS);
	}
	top->priv->next = top;
	if (top->spot <= '1' )
		head->cur_a = top->next;
	else if (top->spot > '1')
		head->cur_b = top->next;
	top->spot += (top->spot % 2 == 0);
	top->next = NULL;
	return (SUCCESS);
}

int	rrx(t_cursor *head, t_stack *top)
{
	if (!top || !top->next)
	{
		if (top)
			top->spot -= (top->spot % 2 != 0);
		return (SUCCESS);
	}
	top->priv->next = top;
	if (top->priv->spot <= '1')
		head->cur_a = top->priv;
	else if (top->priv->spot > '1')
		head->cur_b = top->priv;
	top->priv->spot -= (top->priv->spot % 2 != 0);
	top->priv->priv->next = NULL;
	return (SUCCESS);
}

int	px(t_cursor *head, t_stack *_throw, t_stack *_catch)
{
	if (!_throw)
		return (SUCCESS);
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
		return (SUCCESS);
	}
	_throw->spot = '0';
	return (SUCCESS);
}
