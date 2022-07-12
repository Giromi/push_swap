/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_ten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:08:24 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/12 14:35:03 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_stack	*repeat_next(t_stack *lst, int n) */
/* { */
	/* while (n--) */
		/* lst = lst->next; */
	/* return (lst); */
/* } */

/* t_stack	*repeat_priv(t_stack *lst, int n) */
/* { */
	/* while (n--) */
		/* lst = lst->priv; */
	/* return (lst); */
/* } */

/* static char *sort_two(t_cursor *head, char *order) */
/* { */
	/* if (head->cur_a && head->cur_a->next) */
		/* if (head->cur_a->idx - head->cur_a->next->idx == 1) */
			/* order = sa(head, order); */
	/* if (head->cur_b && head->cur_b->next) */
		/* if (head->cur_b->idx - head->cur_b->next->idx == -1) */
			/* order = sb(head, order); */
	/* return (order); */
/* } */

/* [> static char *sort_three(t_cursor *head, char *order) <] */
/* [> { <] */
	/* [> int	big_idx; <] */

	/* [> big_idx = stack_circle(&head->cur_a); <] */
	/* [> if (head->cur_a->idx == big_idx) <] */
		/* [> order = ra(head, order); <] */
	/* [> else if (head->cur_a->next->idx == big_idx) <] */
		/* [> order = rra(head, order); <] */
	/* [> return (sort_two(head, order)); <] */
/* [> } <] */

/* static char *sort_three(t_cursor *head, char *order) */
/* { */
	/* int	i; */
	/* [> int	half; <] */

	/* i = 0; */
	/* [> half = head->cnt_a / 2 + (head->cnt_a % 2); <] */
	/* while (debug_sort_check(head) == ERROR && i < 12) */
	/* { */
		/* order = sort_two(head, order); */
		/* if (((head->cur_a->idx - head->cur_a->priv->idx == -1) */
			/* || (head->cur_a->idx - head->cur_a->priv->idx == 1)) */
			/* && ((head->cur_a->next->idx == 0) || head->cur_a->next->idx == 1)) */
			/* order = ra(head, order);									//2 차이 나는데 더 크면 내리기/ */
		/* else if ((head->cur_a->idx - head->cur_a->priv->idx == -1) */
			/* || (head->cur_a->idx - head->cur_a->priv->idx == 1)) */
			/* order = rra(head, order);									//2 차이 나는데 더 크면 내리기/ */
		/* else if (head->cur_a->idx > head->cur_a->priv->idx) */
			/* order = ra(head, order);									//2 차이 나는데 더 크면 내리기/ */
		/* [> else if ((head->cur_a->idx - head->cur_a->priv->idx == -1) <] */
				/* [> && (head->cur_a->idx < half)) <] */
			/* [> order = rra(head, order); <] */
		/* i++; */
	/* } */
	/* return (order); */

/* } */

/* static char *sort_four(t_cursor *head, char *order) */
/* { */
	/* if (((head->cur_a->idx == 0 && head->cur_a->next->idx == 3) */
		/* && (head->cur_a->priv->idx == 1)) */
		/* || ((head->cur_a->idx == 0 && head->cur_a->next->idx == 1) */
		/* && (head->cur_a->priv->idx == 2)) */
		/* || ((head->cur_a->idx == 1 && head->cur_a->next->idx == 0) */
		/* && (head->cur_a->priv->idx == 2))) */
		/* order = pb(head, &order); */
	/* [> if (head->cnt_a == 3) <] */
		/* [> return (sort_three(head, order)); <] */
	/* if ((head->cur_a->idx == 2 && head->cur_a->next->idx == 1) */
		/* && (head->cur_a->priv->idx == 3)) */
		/* order = rra(head, order); */
	/* if ((head->cur_a->idx == 2 && head->cur_a->next->idx == 0) */
		/* || (head->cur_a->idx == 3 && head->cur_a->next->idx == 2)) */
	/* { */
		/* order = sa(head, order); */
		/* order = sort_two(head, order); */
	/* } */
	/* if (head->cur_a->idx == 1 && head->cur_a->next->idx == 3) */
	/* { */
		/* order = sa(head, order); */
		/* order = sort_two(head, order); */
	/* } */
	/* if ((head->cur_a->idx == 2 && head->cur_a->priv->idx == 1)// && head->cur_a->next->idx == 0 ) */
		/* || (head->cur_a->idx == 3 && head->cur_a->next->idx == 0)) */
		/* order = ra(head, order); */
	/* while ((head->cur_a->idx == 3 && head->cur_a->priv->idx == 0) */
			/* ||(head->cur_a->idx == 1 && head->cur_a->priv->idx == 3)) */
		/* order = rra(head, order); */
	/* if (head->cur_a->idx == 0 && head->cur_a->next->idx == 3) */
	/* { */
		/* order = sa(head, order); */
		/* order = sort_two(head, order); */
	/* } */
	/* if (head->cur_a->idx == 0 && head->cur_a->priv->idx == 3) */
		/* order = ra(head, order); */
	/* order = sort_three(head, order); */
	/* order = pa(head, order); */
	/* order = sort_two(head, order); */
	/* return (order); */
/* } */

/* static char *sort_five(t_cursor *head, char *order) */
/* { */

	/* while (head->cur_a->idx > 1) */
		/* order = ra(head, order); */
	/* order = pb(head, &order); */
	/* order = sort_four(head, order); */
	/* order = pa(head, order); */
	/* order = sort_two(head, order); */
	/* [> if (head->cur_a->idx - head->cur_a->priv->idx <= -2) <] */
		/* [> order = sa(head, order); <] */

	/* return (order); */
/* } */

/* int	stack_cnt(t_stack *lst) */
/* { */
	/* int	cnt; */

	/* cnt = 0; */
	/* while (lst && cnt++) */
		/* lst = lst->next; */
	/* return (cnt); */
/* } */


/* char *case_check(t_cursor *head, char *order) */
/* { */
	/* if (debug_sort_check(head) == SUCCESS) */
		/* return (NULL); */
	/* if (head->cnt_a == 2) */
		/* return (sort_two(head, order)); */
	/* else if (head->cnt_a == 3) */
		/* return (sort_three(head, order)); */
	/* else if (head->cnt_a == 4) */
		/* return (sort_four(head, order)); */
	/* else if (head->cnt_a == 5) */
		/* return (sort_five(head, order)); */
	/* return (NULL); */
/* } */

	/* int	half; */

	/* half = head->cnt_a / 2 + (head->cnt_a % 2); */

/* int stack_is_goal() */
/* int stack_is_sx() */
/* int stack_is_rx() */
/* int stack_is_rrx() */

/* char *sort_three_rx(t_stack *top, ) */
/* { */
	/* char check_bit; */

	/* [> if (top->where < 2) <] */
	/* rx() */
	/* [> if (top->where < 2) <] */
	/* check_bit = 0BB00110000; */
	/* check_bit |= stack_is_goal; */
	/* check_bit |= stack_is_sx; */
	/* check_bit |= stack_is_rx; */


	/* if (!(check_bit && ~(BIT_RRA | BIT_RRB))) */
		/* rra */
/* } */

/* int sort_three_rrx(t_stack *lst, char **order) */
/* {() */
	/* char check_bit; */

	/* rra */
	/* check_bit = 0BB00001100; */
	/* if ( == SUCCESS) */
		/* return (SUCCESS); */

	/* check_bit |= stack_is_goal; */
	/* check_bit |= stack_is_rx; */
	/* check_bit |= stack_is_rrx; */

	/* if (check_bit && !(check_bit && ~(BIT_RRA | BIT_RRB)) */
	/* { */

	/* } */
	/* return (SUCCESS); */
/* } */

/* char *sort_three_sx() */
/* { */
	/* char check_bit; */

	/* sa */
	/* check_bit = 0BB00000011; */
	/* check_bit = stack_is_goal; */
	/* check_bit |= stack_is_rx; */
	/* check_bit |= stack_is_rrx; */

	/* if (check_bit && OB11000000) */
		/* rra */
/* } */



/* //	0B00000000 : goal */
/* //	0B00000011 : sx */
/* //	0B00001100 : rx */
/* // 	0B00110000 : rrx */
