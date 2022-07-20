/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_ten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:08:24 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/18 21:30:05 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*repeat_next(t_stack *top, int n)
{
	while (n--)
		top = top->next;
	return (top);
}

t_stack	*repeat_priv(t_stack *top, int n)
{
	while (n--)
		top = top->priv;
	return (top);
}

/* int *possible_goal() */
/* int *possible_sx() */
/* int	*possible_rx() */
/* int	*possible_rrx() */

/* char *sort_isra() */
/* { */

/* } */
/* char *sort_issa() */
/* char *sort_isrra(); */

/* static char *sort_three(t_cursor *head, char **order) */
/* { */
	/* int	i; */
	/*   int	half;  */

	/* i = 0; */
	/*   half = head->cnt_a / 2 + (head->cnt_a % 2);  */
	/* while (debug_sort_check(head) == ERROR && i < 12) */
	/* { */
		/* sort_two(head, order); */
		/* if (((head->cur_a->idx - head->cur_a->priv->idx == -1) */
			/* || (head->cur_a->idx - head->cur_a->priv->idx == 1)) */
			/* && ((head->cur_a->next->idx == 0) || head->cur_a->next->idx == 1)) */
			/* ra(head, order);									//2 차이 나는데 더 크면 내리기/ */
		/* else if ((head->cur_a->idx - head->cur_a->priv->idx == -1) */
			/* || (head->cur_a->idx - head->cur_a->priv->idx == 1)) */
			/* rra(head, order);									//2 차이 나는데 더 크면 내리기/ */
		/* else if (head->cur_a->idx > head->cur_a->priv->idx) */
			/* ra(head, order);									//2 차이 나는데 더 크면 내리기/ */
		/*   else if ((head->cur_a->idx - head->cur_a->priv->idx == -1)  */
				/*   && (head->cur_a->idx < half))  */
			/*   rra(head, order);  */
		/* i++; */
	/* } */
	/* return (order); */

/* } */

/* static char *sort_five(t_cursor *head, char **order) */
/* { */

	/* while (head->cur_a->idx > 1) */
		/* ra(head, order); */
	/* pb(head, &order); */
	/* sort_four(head, order); */
	/* pa(head, order); */
	/* sort_two(head, order); */
	/*   if (head->cur_a->idx - head->cur_a->priv->idx <= -2)  */
		/*   sa(head, order);  */

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


	/* int	half; */

	/* half = head->cnt_a / 2 + (head->cnt_a % 2); */




/* int stack_is_sx() */
/* int stack_is_rx() */
/* int stack_is_rrx() */



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

/* int stack_is_goal(t_stack *top, char check_bit) */
/* { */
	/* if (head->cur_b || !top) */
		/* return (BIT_INT); */
	/* return (next_check(top, check_bit)); */
/* } */

/* char *sort_three_rx(t_cursor *head, t_stack *top, char **order) */
/* { */
	/* sx(head->cur_a, order); */
	/* rx(head, head->cur_a, order); */
	/* removed_bit = 0B00111111; */
	/* removed_bit &= ~next_check(top, BIT_ALL); */
	/* removed_bit &= ~next_check(top->next->next, BIT_SS); */
	/* removed_bit &= ~priv_check(top, BIT_RR); */
	/* removed_bit &= ~priv_check(top, BIT_RR); */
	/* removed_bit &= ~priv_check(top->priv->priv, BIT_RRR) */

	/* if (!removed_bit) */
		/* return (order); */
	/* if (removed_bit && BIT_SS) */
		/* return (sa(head, order)); */
	/* if (removed_bit && BIT_RR) */
		/* return (ra(head, order)); */
	/* return (rra(head, head->cnt_a, order)); */
	/* if (!(removed_bit && ~(BIT_RRR))) */
/* } */

/* _three_rx(t_cursor *head, t_stack *top, char **order) */
/* { */
	/* char	removed_bit; */

	/* rx(head, head->cur_a, order); */
	/* removed_bit = 0B00111111; */
	/* removed_bit &= ~next_check(top, BIT_ALL); */
	/* removed_bit &= ~next_check(top->next->next, BIT_SS); */
	/* removed_bit &= ~priv_check(top, BIT_RR); */
	/* removed_bit &= ~priv_check(top, BIT_RR); */

	/* if (!removed_bit) */
		/* return (order); */
	/* if (removed_bit && BIT_SS) */
		/* return (sa(head, order)); */
	/* if (removed_bit && BIT_RR) */
		/* return (ra(head, order)); */
	/* return (rra(head, head->cnt_a, order)); */

/* } */
/* static char *sort_lv1(t_cursor *head, char **order, char command) */
/* { */
	/* int		flag; */
	/* if (command == BIT_SA) */
		/* sx(head->cur_a, order); */
	/* else if (command == BIT_RA) */
		/* rx(head, head->cur_a, order); */
	/* else if (command == BIT_RRA) */
		/* rrx(head, head->cur_a, order); */
	/* if(debug_sort_check(head) == SUCCESS) */
		/* flag = */

	/* if (command == BIT_SA) */
		/* sx(head->cur_a, order)); */
	/* if (command == BIT_RA) */
		/* rrx(head, head->cur_a, order); */
	/* if (command == BIT_RRA) */
		/* rx(head, head->cur_a, order); */
	/* return (order); */
/* } */



char next_check(t_stack *now)
{
	while (now->next)
	{
		if (now->next->tmp_idx - now->tmp_idx != 1)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}

char priv_check(t_stack *now)
{
	t_stack *first;

	first = now;
	while (now->priv != first)
	{
		if (now->tmp_idx - now->priv->tmp_idx != 1)
			return (ERROR);
		now = now->priv;
	}
	return (SUCCESS);
}

char priv_check_swap(t_stack *now, int swap_cnt)
{
	t_stack *first;
	int i;

	i = 0;
	first = now;
	while (now->priv != first)
	{
		if (i >= swap_cnt
			&& (now->priv->tmp_idx - now->priv->priv->tmp_idx == -1))
				return (SUCCESS);
		/* if (i >= swap_cnt */
			/* && (now->priv->tmp_idx == 0 && now->priv->priv->tmp_idx == 1)) */
				/* return (SUCCESS); */
		else if (i < swap_cnt && now->tmp_idx - now->priv->tmp_idx != 1)
				return (ERROR);
		i++;
		now = now->priv;
	}
	return (SUCCESS);
}

/* char *sort_three_check(t_cursor *head, char **order, int end_idx, char *removed) */
/* { */
	/* if (order[end_idx] & BIT_SS) */
		/* *removed = 0B00111111; */
	/* if (order[end_idx] & BIT_RRR) */
		/* *removed = 0B00111111; */
	/* if (order[end_idx] & BIT_RR) */
	/* *removed = 0B00000000; */
	/* *removed = next_check(head->cur_a, BIT_ALL); */
	/* if (*removed == (char)BIT_ALL) */
		/* return (order); */
	/* if (order[end_idx] != (char)BIT_SA) */
		/* *removed |= next_check(head->cur_a->next->next, BIT_SS); */
	/* if (order[end_idx] != (char)BIT_RRA) */
		/* *removed |= priv_check(head->cur_a, BIT_RR); */
	/* if (order[end_idx] != (char)BIT_RA) */
		/* *removed |= priv_check(head->cur_a->priv->priv, BIT_RRR); */

	/* return (order); //(order) */
/* } */



/* char	sort_lv1_check(t_cursor *head) */
/* { */
	/* char	removed; */

	/* removed = BIT_INT; */
	/* removed |= next_check(head->cur_a, BIT_ALL); */
	/* removed |= priv_check(head->cur_a, 1, BIT_RA); */
	/* removed |= priv_check(head->cur_a->priv->priv, 1, BIT_RRA); */
	/* return (removed); */
/* } */

/* static char *sort_three(t_cursor *head, char **order, char command) */
/* { */
	/* char	bit; */

	/* if(debug_sort_check(head) == SUCCESS) */
		/* return (BIT_INT); */
	/* debug_print(head, 1); */
	/* if (command & BIT_SA) */
		/* sx(head->cur_a, NULL); */
	/* if (command & BIT_RA) */
		/* rx(head, head->cur_a, NULL); */
	/* if (command & BIT_RRA) */
		/* rrx(head, head->cur_a, NULL); */
	/* if (command & (BIT_RA | BIT_RRA)) */
		/* sort_two(head->cur_a, NULL, NULL); */
	/* debug_print(head, 1); */
	/* bit = sort_lv1_check(head); */
	/* if (command & (BIT_RA | BIT_RRA)) */
		/* sort_two(NULL, head->cur_a, NULL); */
	/* if (command & BIT_RA) */
		/* rrx(head, head->cur_a, NULL); */
	/* if (command & BIT_RRA) */
		/* rx(head, head->cur_a, NULL); */
	/* if (command & BIT_SA) */
		/* sx(head->cur_a, NULL); */
	/* debug_print(head, 1); */
	/* if (bit == (char)BIT_INT || bit == (char)BIT_ALL) */
		/* return (bit); */
	/* return (command); */
/* } */

/* char *case_check(t_cursor *head, char **order) */
/* { */
	/* char	bit; */

	/* bit = BIT_INT; */
	/* if (head->cnt_a == 2) */
		/* return (sort_two(head->cur_a, NULL, order)); */
	/* if (sort_three(head, BIT_SA)) */
		/* sx(head->cur_a, order); */
	/* if (sort_three(head, BIT_RA)) */
	/* { */
		/* rx(head, head->cur_a, order); */
		/* sort_two(head->cur_a, NULL, order); */
	/* } */
	/* if (sort_three(head, BIT_RRA)) */
	/* { */
		/* rrx(head, head->cur_a, order); */
		/* sort_two(head->cur_a, NULL, order); */
	/* } */
	/* if (!bit) */
		/* return (order); */
	/* return (order); */
	/* return (case_check(head, order)); */
char	stack_isgoal(t_stack *top)
{
	if (next_check(top) == ERROR)
		return (BIT_INT);
	return (BIT_ALL);
}



/* char	stack_isra2(t_cursor *head, t_stack *top, char **order) */
/* { */
	/* if (priv_check(top->next) == ERROR) */
		/* return (ERROR); */
	/* rx(head, head->cur_a, order); */
	/* rx(head, head->cur_a, order); */
	/* return (SUCCESS); */
/* } */


char	stack_isrra(t_cursor *head, t_stack *top, char **order)
{
	if (priv_check(top->priv->priv) == ERROR)
		return (BIT_INT);
	rrx(head, head->cur_a, order);
	return (BIT_RRA);
}


/* char	stack_isrra2(t_cursor *head, t_stack *top, char **order) */
/* { */
	/* if (priv_check(top->priv->priv->priv) == ERROR) */
		/* return (BIT_INT); */
	/* rrx(head, head->cur_a, order); */
	/* rrx(head, head->cur_a, order); */
	/* return (SUCCESS); */
/* } */



/* char	*sort_two_ra(t_cursor *head, t_stack *left, t_stack *right, char **order) */
/* { */
	/* if (left && left->next) */
		/* if (left->tmp_idx - left->priv->tmp_idx == 1) */
			/* rx(head, left, order); */
	/* if (right && right->next) */
		/* if (right->tmp_idx - right->priv->tmp_idx == -1) */
			/* rx(head, right, order); */
	/* return (order); */
/* } */

/* char	*sort_two_rra(t_cursor *head, t_stack *left, char **order) */
/* { */
	/* if (left && left->next) */
		/* if (left->tmp_idx - left->priv->tmp_idx == 1 */
				/* && left->tmp_idx == head->cnt_a - 1) */
			/* rrx(head, left, order); */
	/* return (order); */
/* } */



/* static	char sort_three_sa(t_cursor *head, char **order) */
/* { */
	/* if (head->cur_a && head->cur_a->next->next) */
		/* if (head->cur_a->next->next->tmp_idx - head->cur_a->tmp_idx == 1) */
			/* return (sx(head, head->cur_a, order)); */
	/* return (BIT_INT); */
/* } */
static	char sort_swap(t_cursor *head, t_stack *top, char **order)
{
	if (top && top->next)
	{
		if (top->tmp_idx - top->next->tmp_idx == 1)
			return (sx(head, top, order));
		if ((top->tmp_idx == 0 && top->next->tmp_idx == head->cnt_a - 1)
				&& !next_check(top->next->next))
			return (sx(head, top, order));
	}
	return (BIT_INT);
}

/* static	char sort_isswap2(t_cursor *head, t_stack *top, char **order) */
/* { */
	/* if (top && top->next) */
		/* if (top->tmp_idx - top->next->next->tmp_idx == -1) */
			/* return (sx(head, top, order)); */
	/* return (BIT_INT); */
/* } */

char	stack_isrotate(t_cursor *head, char **order, char priv_command, int n)
{
	char bit;
	int	i;

	bit = BIT_INT;

	i = 0;
	if (priv_command != BIT_RA && bit == BIT_INT
			&& !priv_check(repeat_priv(head->cur_a, 2 + n)))
		while (i++ < n + 1)
			bit = rrx(head, head->cur_a, order);
	i = 0;
	if (priv_command != BIT_RRA && bit == BIT_INT
			&& !priv_check(repeat_next(head->cur_a, n)))
		while (i++ < n + 1)
			bit = rx(head, head->cur_a, order);
	return (bit);
}




/* static	char sort_lv1(t_cursor *head, char **order, char priv_command) */
/* { */
	/* int		n; */

	/* if (priv_command != BIT_SA) */
		/* sort_isswap(head, head->cur_a, order); */
	/* n = 0; */
	/* while (n < head->cnt_a / 2) */
		/* stack_isrotate(head, order, priv_command, n++); */
	/* return (stack_isgoal(head->cur_a)); */
/* } */


char sort_rotate_goal(t_cursor *head, char **order, char priv_command)
{
	int		n;

	if (priv_command != BIT_SA)
		priv_command = sort_swap(head, head->cur_a, order);
	if ((priv_command != BIT_RRA && head->cur_a->next->tmp_idx != 1
			&& (head->cur_a->next->tmp_idx - head->cur_a->next->next->tmp_idx == 1)))
		priv_command = rx(head, head->cur_a, order);
	n = 0;
	while (n < head->cnt_a / 2)
		stack_isrotate(head, order, priv_command, n++);
	if (stack_isgoal(head->cur_a))
		return (BIT_ALL);
	if (priv_command == BIT_SA)
		sx(head, head->cur_a, order);
	return (BIT_INT);
}

char	stack_isroswap(t_cursor *head, char **order, char priv_command, int n)
{
	char bit;
	int	i;

	bit = BIT_INT;
	i = 0;
	if (priv_command != BIT_RA && bit == BIT_INT
		&& !priv_check_swap(repeat_priv(head->cur_a, 2 + n), head->cnt_a - 3))
		while (i++ < n + 1)
			bit = rrx(head, head->cur_a, order);
	i = 0;
	if (priv_command != BIT_RRA && bit == BIT_INT
			&& !priv_check_swap(repeat_next(head->cur_a, n), head->cnt_a - 3))
		while (i++ < n + 1)
			bit = rx(head, head->cur_a, order);
	sort_swap(head, head->cur_a, order);
	return (stack_isgoal(head->cur_a));
}

static	char sort_rotate_swap(t_cursor *head, char **order, char priv_command)
{
	int		n;
	char	check;

	n = 0;
	check = BIT_INT;
	while (n < head->cnt_a / 2 && check == BIT_INT) check = stack_isroswap(head, order, priv_command, n++);
	if (!check)
		check = sort_rotate_goal(head, order, BIT_INT);
	return (check);
}


	/* n = 1; */
	/* rx(head, head->cur_a, order); */
	/* sort_two(head->cur_a, order); */
	/* if (stack_isgoal(head->cur_a) == SUCCESS) */
		/* return (order); */
	/* rrx(head, head->cur_a, order); */

	/* rrx(head, head->cur_a, order); */
	/* rrx(head, head->cur_a, order); */
	/* sort_two(head->cur_a, order); */
	/* if (stack_isgoal(head->cur_a) == SUCCESS) */
		/* return (order); */
	/* rx(head, head->cur_a, order); */
	/* rx(head, head->cur_a, order); */
/* char	sort_three(t_cursor *head, char **order) */
/* { */
	/* sort_swap(head->cur_a, order); */
	/* sort_lv1(head, head->cur_a, order); */


static char sort_try_method_case_four(t_cursor *head, char **order)
{
	if (sort_rotate_goal(head, order, rx(head, head->cur_a, order)))
		return (BIT_ALL);
	rrx(head, head->cur_a, order);
	if (sort_rotate_goal(head, order, rrx(head, head->cur_a, order)))
		return (BIT_ALL);
	rx(head, head->cur_a, order);
	if (sort_rotate_goal(head, order, rx(head, head->cur_a, order)))
		return (BIT_ALL);
	rrx(head, head->cur_a, order);
	return (BIT_INT);
}

/* char sort_three(t_cursor *head, char **order) */
/* { */
	/* if (sort_lv1(head, order, rrx(head, head->cur_a, order))) */
		/* return (BIT_ALL); */
	/* rx(head, head->cur_a, order); */
	/* return (BIT_INT); */
/* } */

char	sort_four(t_cursor *head, char **order, char priv_command)
{
	char	check;

	check = stack_isgoal(head->cur_a);
	if (!check && head->cnt_a == 4)
		check = sort_rotate_swap(head, order, priv_command);
	if (!check && head->cnt_a == 4)
		check = sort_try_method_case_four(head, order);


	return (check);
}

char	sort_five(t_cursor *head, char **order)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (repeat_next(head->cur_a, i)->tmp_idx > 1)
		i++;
	while (repeat_priv(head->cur_a, i)->tmp_idx > 1)
		j++;
	if (i <= j)
		while (i--)
			rx(head, head->cur_a, order);
	else if (i > j)
		while (j--)
			rrx(head, head->cur_a, order);
	px(head, head->cur_a, head->cur_b, order);
	return (sort_four(head, order, BIT_PB));
}


char	case_check(t_cursor *head,char **order, char priv_command)
{
	char	check;

	check = stack_isgoal(head->cur_a);
	if (!check && head->cnt_a)
		check = sort_rotate_goal(head, order, priv_command);
	if (!check && head->cnt_a == 4)
		check = sort_four(head, order, priv_command);
	if (!check && head->cnt_a == 7)
		check = sort_five(head, order);
	px(head, head->cur_b, head->cur_a, order);
	sort_swap(head, head->cur_a, order);
	return (check);
}
