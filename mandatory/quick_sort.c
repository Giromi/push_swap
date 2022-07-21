/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:49:31 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 11:28:52 by minsuki2         ###   ########.fr       */
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

void pivot_setting(int *pv1, int *pv2, int offset, int n)
{
	*pv1 = n / 3 + offset;
	*pv2 = 2 * (n / 3) + (n % 3 == 2) + offset;
	if (n / 3 < 4)
	{
		*pv2 = n - 4 + offset;
		*pv1 = (n - 4) / 2 + ((n - 4) % 2 != 0) + offset;
	}
}

void stack_b_to_a(t_cursor *head, char **order, int offset, int n, int *flag)
{
	int pv1;
	int pv2;
	t_cnt	count;

	*flag = 1;
	ft_bzero(&count, sizeof(t_cnt));
	if (n <= 4 && !wall_check_stack(head, order, n, '2'))
		while (n--)
			px(head, head->cur_b, head->cur_a, order);
	pivot_setting(&pv1, &pv2, offset, n);
	while (n-- > 0)
	{
		if (head->cur_b->idx < pv1 && ++count.rb)
			rx(head, head->cur_b, order);
		else if ((head->cur_b->idx >= pv1 && ++count.pa)
			&& px(head, head->cur_b, head->cur_a, order))
			if (head->cur_a->idx < pv2 && ++count.ra)
				rx(head, head->cur_a, order);
	}
	stack_go_to_top(head, order, '3', count.rb);
	stack_a_to_b(head, order, pv1, count.pa - count.ra, flag);
	stack_go_to_top(head, order, '1', count.ra);
	stack_a_to_b(head, order, offset, count.ra, flag);
	if (count.rb)
		stack_b_to_a(head, order, offset, count.rb, flag);
}

void	stack_a_to_b(t_cursor *head, char **order, int offset, int n, int *flag)
{
	int pv1;
	int pv2;
	t_cnt	count;

	ft_bzero(&count, sizeof(t_cnt));
	if (n <= 4 && (head)!wall_check_stack(head, order, n, '0'))
		return ;
	pivot_setting(&pv1, &pv2, offset, n);
	while (n-- > 0)
	{
		if (head->cur_a->idx >= pv2 && ++count.ra)
			rx(head, head->cur_a, order);
		else if ((head->cur_a->idx < pv2 && ++count.pb)
			&& px(head, head->cur_a, head->cur_b, order))
			if (head->cur_b->idx < pv1 && ++count.rb)
				rx(head, head->cur_b, order);
	}
	if (*flag != 0)
		stack_go_to_top(head, order, '1', count.ra);
	stack_a_to_b(head, order, pv2, count.ra, flag);
	stack_b_to_a(head, order, pv1, count.pb - count.rb, flag);
	if (offset != 0)
		stack_go_to_top(head, order, '3', count.rb);
	stack_b_to_a(head, order, offset, count.rb, flag);
}
