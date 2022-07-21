/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:04:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 14:44:08 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int where_idx_n(t_cursor *head, int n, char spot)
{
	int		find_idx;
	t_stack *tmp;

	tmp = head->cur_a;
	if (spot == '2')
		tmp = head->cur_b;
	if (!tmp)
		return (ERROR);
	find_idx = tmp->idx;
	while (tmp && n--)
	{
		if (spot == '0' && tmp->idx < find_idx)
			find_idx = tmp->idx;
		else if (spot == '2' && tmp->idx > find_idx)
			find_idx = tmp->idx;
		tmp = tmp->next;
	}
	return (find_idx);
}

int	wall_sort_two(t_cursor *head, char spot)
{
	if (spot == '0')
	{
		if (!head->cur_a || !head->cur_a->next)
			return (ERROR);
		if (head->cur_a->idx > head->cur_a->next->idx)
			sx(head, head->cur_a);
	}
	if (spot == '2')
	{
		if (!head->cur_b || !head->cur_b->next)
			return (ERROR);
		if (head->cur_b->idx < head->cur_b->next->idx)
			sx(head, head->cur_b);
	}
	return (SUCCESS);
}

int wall_sort_three(t_cursor *head, char spot)
{
	if (spot == '0')
	{
		wall_sort_two(head, spot);
		px(head, head->cur_a, head->cur_b);
		wall_sort_two(head, spot);
		px(head, head->cur_b, head->cur_a);
		wall_sort_two(head, spot);
	}
	if (spot == '2')
	{
		wall_sort_two(head, spot);
		px(head, head->cur_b, head->cur_a);
		wall_sort_two(head, spot);
		px(head, head->cur_a, head->cur_b);
		wall_sort_two(head, spot);
	}
	return (SUCCESS);
}

void wall_a_sort_four(t_cursor *head, char spot)
{
	int	i;
	int	find_idx;

	i = 0;
	find_idx = where_idx_n(head, 4, spot);
	while (head->cur_a->idx != find_idx && ++i)
		rx(head, head->cur_a);
	px(head, head->cur_a, head->cur_b);
	while (i--)
	{
		rrx(head, head->cur_a);
		if (head->cur_a->idx == find_idx + 1)
		{
			px(head, head->cur_a, head->cur_b);
			find_idx = ERROR;
		}
	}
	wall_sort_two(head, spot);
	if (find_idx != ERROR)
		wall_sort_three(head, spot);
	else
		px(head, head->cur_b, head->cur_a);
	px(head, head->cur_b, head->cur_a);
}

void wall_b_sort_four(t_cursor *head, char spot)
{
	int	i;
	int	find_idx;

	i = 0;
	find_idx = where_idx_n(head, 4, spot);
	while (head->cur_b->idx != find_idx && ++i)
		rx(head, head->cur_b);
	px(head, head->cur_b, head->cur_a);
	while (i--)
	{
		rrx(head, head->cur_b);
		if (head->cur_b->idx == find_idx - 1)
		{
			px(head, head->cur_b, head->cur_a);
			find_idx = ERROR;
		}
	}
	wall_sort_two(head, spot);
	if (find_idx != ERROR)
		wall_sort_three(head, spot);
	else
	{
		//wall_sort_two(head, '2');
		px(head, head->cur_a, head->cur_b);
	}
	px(head, head->cur_a, head->cur_b);
}


int wall_check_stack(t_cursor *head, int n, char spot)
{
	if (next_check_nspot(head, n, spot) == SUCCESS)
		return (SUCCESS);
	if (n == 2)
		wall_sort_two(head, spot);
	if (n == 3)
		wall_sort_three(head, spot);
	if (n == 4)
	{
		if (spot == '0')
			wall_a_sort_four(head, spot);
		if (spot == '2')
			wall_b_sort_four(head, spot);
	}
	return (SUCCESS);
}

