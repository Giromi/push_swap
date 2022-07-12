/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:49:31 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/12 12:06:19 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* char *quick_sort(t_cursor *head, char *order) */
/* { */
	/* int	pivot1; */
	/* int	pivot2; */
	/* int n; */

	/* [> pivot1 = head->cnt_a / 3 + (head->cnt_a % 2 == 2); <] */
	/* [> pivot2 = pivot1 * 2 + (head->cnt_a % 2 > 0); <] */

	/* debug_print(head, 0); */
	/* pivot1 = head->cnt_a / 3; */
	/* pivot2 = pivot1 * 2 + (head->cnt_a % 3 == 2); */
	/* for (int i = 0; i < pivot1; i++) */
		/* ft_printf("%d ", i); */
	/* ft_printf("/ "); */
	/* for (int i = pivot1; i < pivot2; i++) */
		/* ft_printf("%d ", i); */
	/* ft_printf("/ "); */
	/* for (int i = pivot2; i < head->cnt_a; i++) */
		/* ft_printf("%d ", i); */
	/* printf("\n"); */
	/* n = head->cnt_a; */
	/* while (1) */
	/* { */
		/* if (head->cur_a->idx < pivot1) */
		/* { */
			/* order = pb(head, order); */
			/* order = rb(head, order); */
		/* } */
		/* else if (head->cur_a->idx < pivot2) */
			/* order = pb(head, order); */
		/* else */
			/* order = ra(head, order); */
		/* if ((head->cnt_a <= n - pivot2)) */
			/* break ; */
	/* } */
	/* order = case_check(head, order); */
	/* debug_print(head, 1); */
	/* return (order); */
/* } */

/* void stack_b_to_b_top(t_cursor *head, char **order, int pv1, char reverse) */
/* { */
	/* while (head->cur_b->priv < pv1) */
		/* rrb(head, *order); */
/* } */

/* void stack_b_to_a(t_cursor *head, char **order) */
/* { */

	/* if (head->cur_a->idx < pivot1) */
	/* { */
		/* pa(head, *order); */
		/* ra(head, *order); */
		/* debug_print(head, 1); */
	/* } */
	/* else if (head->cur_a->idx < pivot2) */
	/* { */
		/* order = pa(head, *order); */
		/* debug_print(head, 1); */
	/* } */
	/* else */
		/* order = sa(head, *order); */
	/* stack_b_to_b_top(head, order, pv1); */
	/* if (head->cnt_b > head) */
		/* stack_b_to_a(head, order); */
/* } */


/* void stack_a_to_b(t_cursor *head, char **order, char reverse) */
/* { */
	/* int	pv1; */
	/* int	pv2; */

	/* pv1 = head->cnt_a / 3; */
	/* pv2 = pivot1 * 2 + (head->cnt_a % 3 == 2); */

	/* if (head->cur_a->idx < pivot1) */
	/* { */
		/* pb(head, *order); */
		/* rb(head, *order); */
		/* debug_print(head, 1); */
	/* } */
	/* else if (head->cur_a->idx < pivot2) */
	/* { */
		/* order = pb(head, *order); */
		/* debug_print(head, 1); */
	/* } */
	/* else */
		/* order = ra(head, *order); */
	/* stack_b_to_b_top(head, order, pv1); */
	/* if (head->cnt_a > pv1) */
		/* stack_a_to_b(head, order); */
	/* order = case_check(head, order); */
	/* stack_b_to_a(head, order); */
/* } */







/* void	recursive_sort(t_cursor *head, char *order) */
/* { */

	/* stack_a_to_b(head, &order); */
	/* order = case_check(head, order); */
	/* stack_b_to_a(head, &order); */
	/* return ; */
/* } */


