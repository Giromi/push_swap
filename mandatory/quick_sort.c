/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:49:31 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 10:11:29 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_go_to_top(t_cursor *head, char **order, int spot, int cnt)
{
	while (spot == '1' && cnt--)
		rrx(head, head->cur_a, order);
	while (spot == '3' && cnt--)
		rrx(head, head->cur_b, order);
}

void stack_b_to_a(t_cursor *head, char **order, int offset, int n, int *flag)
{
	int limit = 4;
	int pv1;
	int pv2;
	t_cnt	count;

	*flag = 1;
	ft_bzero(&count, sizeof(t_cnt));
	pv1 = n / 3 + offset;
	pv2 = 2 * (n / 3) + (n % 3 == 2) + offset;
	if (n <= limit)
	{
		wall_check_stack(head, order, n, '2');
		while (n--)
			px(head, head->cur_b, head->cur_a, order);
		return ;
	}
	else if (n / 3 < limit)
	{
		pv2 = n - limit + offset;
		pv1 = (n - limit) / 2 + ((n - limit) % 2 != 0) + offset;
	}
	while (n--)
	{
		if (head->cur_b->idx < pv1 && ++count.rb)
			rx(head, head->cur_b, order);
		else if (head->cur_b->idx >= pv1 && ++count.pa)
		{
			px(head, head->cur_b, head->cur_a, order);
			if (head->cur_a->idx < pv2 && ++count.ra)
				rx(head, head->cur_a, order);
		}
	}
//	debug_print(head, 1);
	stack_go_to_top(head, order, '3', count.rb);
//	debug_print(head, 1);
	stack_a_to_b(head, order, pv1, count.pa - count.ra, flag);
//	debug_print(head, 1);
	stack_go_to_top(head, order, '1', count.ra);
//	debug_print(head, 1);
	stack_a_to_b(head, order, offset, count.ra, flag);
//	debug_print(head, 1);
	stack_b_to_a(head, order, offset, count.rb, flag);
//	debug_print(head, 1);
}

void	stack_a_to_b(t_cursor *head, char **order, int offset, int n, int *flag)
{
	int limit = 4;
	int pv1;
	int pv2;
	t_cnt	count;

	ft_bzero(&count, sizeof(t_cnt));
	pv1 = n / 3 + offset;
	pv2 = 2 * (n / 3) + (n % 3 == 2) + offset;
	if (n <= limit)
	{
		if (head->cnt_a == 5)
			case_check(head, order);
		wall_check_stack(head, order, n, '0');
		return ;
	}
	else if (n / 3 < limit)
	{
		pv2 = n - limit + offset;
		pv1 = (n - limit) / 2 + ((n - limit) % 2 != 0) + offset;
	}
	while (n--)
	{
		if (head->cur_a->idx >= pv2 && ++count.ra)
		{
			rx(head, head->cur_a, order);
		}
		else if (head->cur_a->idx < pv2 && ++count.pb)
		{
			px(head, head->cur_a, head->cur_b, order);
			if (head->cur_b->idx < pv1 && ++count.rb)
			{
				rx(head, head->cur_b, order);
			}
		}
	}
//	debug_print(head, 1);
	if (*flag != 0)
		stack_go_to_top(head, order, '1', count.ra);
	stack_a_to_b(head, order, pv2, count.ra, flag);
//	debug_print(head, 1);
	stack_b_to_a(head, order, pv1, count.pb - count.rb, flag);
//	debug_print(head, 1);
	if (offset != 0)
		stack_go_to_top(head, order, '3', count.rb);
//	debug_print(head, 1);
	stack_b_to_a(head, order, offset, count.rb, flag);
//	debug_print(head, 1);
}
