/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:04:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 09:57:55 by minsuki2         ###   ########.fr       */
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

int	wall_sort_two(t_cursor *head, char **order, char spot)
{
	if (spot == '0')
	{
		if (!head->cur_a || !head->cur_a->next)
			return (ERROR);
		if (head->cur_a->idx > head->cur_a->next->idx)
			sx(head, head->cur_a, order);
	}
	if (spot == '2')
	{
		if (!head->cur_b || !head->cur_b->next)
			return (ERROR);
		if (head->cur_b->idx < head->cur_b->next->idx)
			sx(head, head->cur_b, order);
	}
	return (SUCCESS);
}

int wall_sort_three(t_cursor *head, char **order, char spot)
{
	if (spot == '0')
	{
		wall_sort_two(head, order, spot);
		px(head, head->cur_a, head->cur_b, order);
		wall_sort_two(head, order, spot);
		px(head, head->cur_b, head->cur_a, order);
		wall_sort_two(head, order, spot);
	}
	if (spot == '2')
	{
		wall_sort_two(head, order, spot);
		px(head, head->cur_b, head->cur_a, order);
		wall_sort_two(head, order, spot);
		px(head, head->cur_a, head->cur_b, order);
		wall_sort_two(head, order, spot);
	}
	return (SUCCESS);
}

void wall_a_sort_four(t_cursor *head, char **order, char spot)
{
	int	i;
	int	find_idx;

	i = 0;
	find_idx = where_idx_n(head, 4, spot);
	while (head->cur_a->idx != find_idx && ++i)
		rx(head, head->cur_a, order);
	px(head, head->cur_a, head->cur_b, order);
	while (i--)
	{
		rrx(head, head->cur_a, order);
		if (head->cur_a->idx == find_idx + 1)
		{
			px(head, head->cur_a, head->cur_b, order);
			find_idx = ERROR;
		}
	}
	wall_sort_two(head, order, spot);
	if (find_idx != ERROR)
		wall_sort_three(head, order, spot);
	else
		px(head, head->cur_b, head->cur_a, order);
	px(head, head->cur_b, head->cur_a, order);
}

void wall_b_sort_four(t_cursor *head, char **order, char spot)
{
	int	i;
	int	find_idx;

	i = 0;
	find_idx = where_idx_n(head, 4, spot);
	while (head->cur_b->idx != find_idx && ++i)
		rx(head, head->cur_b, order);
	px(head, head->cur_b, head->cur_a, order);
	while (i--)
	{
		rrx(head, head->cur_b, order);
		if (head->cur_b->idx == find_idx - 1)
		{
			px(head, head->cur_b, head->cur_a, order);
			find_idx = ERROR;
		}
	}
	wall_sort_two(head, order, spot);
	if (find_idx != ERROR)
		wall_sort_three(head, order, spot);
	else
	{
		//wall_sort_two(head, order, '2');
		px(head, head->cur_a, head->cur_b, order);
	}
	px(head, head->cur_a, head->cur_b, order);
}

void wall_a_sort_five(t_cursor *head, char **order, char spot)
{
	int	i;
	int	find_idx;

	i = 0;
	find_idx = where_idx_n(head, 5, spot);
	while (head->cur_a->idx != find_idx && ++i)
		rx(head, head->cur_a, order);
	px(head, head->cur_a, head->cur_b, order);
	while (i--)
	{
		rrx(head, head->cur_a, order);
		if (head->cur_a->idx == find_idx + 1)
		{
			px(head, head->cur_a, head->cur_b, order);
			find_idx = ERROR;
		}
	}
	wall_sort_three(head, order, spot);
	if (find_idx != ERROR)
		wall_a_sort_four(head, order, spot);
	else
		px(head, head->cur_b, head->cur_a, order);
	px(head, head->cur_b, head->cur_a, order);
}

void wall_b_sort_five(t_cursor *head, char **order, char spot)
{
	int	i;
	int	find_idx;

	i = 0;
	find_idx = where_idx_n(head, 5, spot);
	while (head->cur_b->idx != find_idx && ++i)
		rx(head, head->cur_b, order);
	px(head, head->cur_b, head->cur_a, order);
	while (i--)
	{
		rrx(head, head->cur_b, order);
		if (head->cur_b->idx == find_idx - 1)
		{
			px(head, head->cur_b, head->cur_a, order);
			find_idx = ERROR;
		}
	}
	wall_sort_three(head, order, spot);
	if (find_idx != ERROR)
		wall_b_sort_four(head, order, spot);
	else
		px(head, head->cur_a, head->cur_b, order);
	px(head, head->cur_a, head->cur_b, order);
}

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

int wall_check_stack(t_cursor *head, char **order, int n, char spot)
{
	if (next_check_nspot(head, n, spot) == SUCCESS)
		return (SUCCESS);
	if (n == 2)
		wall_sort_two(head, order, spot);
	if (n == 3)
		wall_sort_three(head, order, spot);
	if (n == 4)
	{
		if (spot == '0')
			wall_a_sort_four(head, order, spot);
		if (spot == '2')
			wall_b_sort_four(head, order, spot);
	}
	if (n == 5)
	{
		if (spot == '0')
			wall_a_sort_five(head, order, spot);
		if (spot == '2')
			wall_b_sort_five(head, order, spot);
	}
	return (SUCCESS);
}

