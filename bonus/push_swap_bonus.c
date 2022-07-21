/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:41:59 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 15:43:12 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char stdio_test(t_cursor *head, char **order)
{
	char		*buf;

	buf = (char *)malloc(sizeof(char) * 5);
	while (1)
	{
		debug_print(head, 1);
		ft_bzero(buf, sizeof(char) * 5);
		write(1, "input => ", 9);
		read(0, buf, 4);
		if (ft_strnstr(buf, "00\n", 3))
			break ;
		else if (ft_strnstr(buf, "pa\n", 3))
			px(head, head->cur_b, head->cur_a, order);
		else if (ft_strnstr(buf, "pb\n", 3))
			px(head, head->cur_a, head->cur_b, order);
		else if (ft_strnstr(buf, "sa\n", 3))
			sx(head, head->cur_a, order);
		else if (ft_strnstr(buf, "sb\n", 3))
			sx(head, head->cur_b, order);
		else if (ft_strnstr(buf, "ra\n", 3))
			rx(head, head->cur_a, order);
		else if (ft_strnstr(buf, "rb\n", 3))
			rx(head, head->cur_b, order);
		else if (ft_strnstr(buf, "rra\n", 4))
			rrx(head, head->cur_a, order);
		else if (ft_strnstr(buf, "rrb\n", 4))
			rrx(head, head->cur_b, order);
		else if (ft_strnstr(buf, "ss\n", 3))
		{
			sx(head, head->cur_a, order);
			sx(head, head->cur_b, order);
		}
		else if (ft_strnstr(buf, "rr\n", 3))
		{
			rx(head, head->cur_a, order);
			rx(head, head->cur_b, order);
		}
		else if (ft_strnstr(buf, "rrr\n", 4))
		{
			rrx(head, head->cur_a, order);
			rrx(head, head->cur_b, order);
		}
		else
		{
			ft_printf("retry!!!\n");
			continue ;
		}
		if (!order)
			ft_printf("isproblem\n");
	}
	free(buf);
	return (BIT_ALL);
}

