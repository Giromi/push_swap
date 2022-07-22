/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:41 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 21:57:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	stack_circle(t_stack **lst)
{
	int		max_idx;
	t_stack	*tmp;
	t_stack	*last;

	max_idx = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->idx > max_idx)
			max_idx = tmp->idx;
		if (!tmp->next)
			last = tmp;
		tmp = tmp->next;
	}
	if (!(*lst)->priv)
		(*lst)->priv = last;
	return (max_idx + 1);
}

void	stack_head_set(t_cursor *head, t_stack *first)
{
	if (!head || !first)
		return ;
	head->cur_a = first;
	head->cur_b = NULL;
	head->cnt_a = stack_circle(&first);
	head->cnt_b = 0;
	head->order = NULL;
}

static int	follow_command_len3(t_cursor *head)
{
	if (ft_strnstr(head->order, "pa\n", 3))
		return (px(head, head->cur_b, head->cur_a));
	else if (ft_strnstr(head->order, "pb\n", 3))
		return (px(head, head->cur_a, head->cur_b));
	else if (ft_strnstr(head->order, "sa\n", 3))
		return (sx(head->cur_a));
	else if (ft_strnstr(head->order, "sb\n", 3))
		return (sx(head->cur_b));
	else if (ft_strnstr(head->order, "ra\n", 3))
		return (rx(head, head->cur_a));
	else if (ft_strnstr(head->order, "rb\n", 3))
		return (rx(head, head->cur_b));
	else if (ft_strnstr(head->order, "ss\n", 3))
	{
		sx(head->cur_a);
		return (sx(head->cur_b));
	}
	else if (ft_strnstr(head->order, "rr\n", 3))
	{
		rx(head, head->cur_a);
		return (rx(head, head->cur_b));
	}
	return (ERROR);
}

static int	follow_command_len4(t_cursor *head)
{
	if (ft_strnstr(head->order, "rra\n", 4))
		return (rrx(head, head->cur_a));
	else if (ft_strnstr(head->order, "rrb\n", 4))
		return (rrx(head, head->cur_b));
	else if (ft_strnstr(head->order, "rrr\n", 4))
	{
		rrx(head, head->cur_a);
		return (rrx(head, head->cur_b));
	}
	return (ERROR);
}

int	stdio_input(t_cursor *head)
{
	int		i;
	int		check;

	while (1)
	{
		i = 0;
		check = ERROR;
		head->order = get_next_line(0);
		if (!head->order)
			break ;
		while (head->order[i] && head->order[i] != '\n')
			i++;
		if (head->order[i] == '\0')
			return (ERROR);
		if (check == ERROR)
			check = follow_command_len3(head);
		if (check == ERROR)
			check = follow_command_len4(head);
		if (check == ERROR)
			return (ERROR);
		free(head->order);
	}
	return (SUCCESS);
}
