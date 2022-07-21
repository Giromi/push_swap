/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:14:28 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 13:16:07 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_counteract(char *str, int *len, char add)
{
	if (((str[*len - 2] | add) == (BIT_RRA | BIT_RA))
			|| ((str[*len - 2] | add) == (BIT_RRB | BIT_RB))
			|| ((str[*len - 2] | add) == (char)(BIT_PA | BIT_PB))
			|| (str[*len - 2] == BIT_SA && add == BIT_SA)
			|| (str[*len - 2] == BIT_SB && add == BIT_SB))
	{
		(*len) -= 2;
		return (BIT_INT);
	}
	return (add);
}

int stack_pushidx(t_stack *_throw, t_stack *_catch)
{
	int criterion_num;
	t_stack *push;

	criterion_num = _throw->num;
	_throw->tmp_idx = 0;
	push = _throw;
	while (_throw || _catch)
	{
		if (_throw && _throw->num > criterion_num)
			_throw->tmp_idx--;
		if (_catch && _catch->num > criterion_num)
			_catch->tmp_idx++;
		else if(_catch && _catch->num < criterion_num)
			push->tmp_idx++;
		if (_throw)
			_throw = _throw->next;
		if (_catch)
			_catch = _catch->next;
	}
	return (SUCCESS);
}
