/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 22:18:13 by minsuki2         ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */

#include "push_swap.h"

char	stdio_test(t_cursor *head, char **order);
int		debug_sort_check(t_cursor *head);
void	only_exit(void);

static int	check_part(char **av, int *num, char *flag)
{
	char	*tmp;
	char	*pos;

	*flag = 'f';
	pos = ft_strchr_null(*av, ' ');
	tmp = *av;
	if (*tmp == '-' || *tmp == '+')
		if (!(ft_isdigit((*(++tmp)))))
			return (ERROR);
	while (tmp < pos)
		if (!(ft_isdigit(*tmp++)))
			return (ERROR);
	*num = ft_simple_atoi(*av);
	if ((*num > 0 && **av == '-') || (*num < 0 && **av != '-'))
		return (ERROR);
	*av = pos;
	return (SUCCESS);
}

int av_check(char **av, t_stack **input)
{
	int		num;
	char	flag;
	t_stack	*new;

	while (*(++av))
	{
		flag = '\0';
		while (1)					// "" 들어오면 error 나와야해서**av 조건 사용 안됨
		{
			while (ft_issp(**av))
				(*av)++;
			if (flag && !**av)
				break;
			if ((!flag && !**av) || check_part(av, &num, &flag) == ERROR)
				return (ERROR);
			new = stack_lstnew(num);
			if (stack_lstadd_back(input, new) == ERROR)
			{
				if (new)
					free(new);
				return (ERROR);
			}
		}
	}
	return (SUCCESS);
}

int main(int ac, char *av[])
{
	atexit(only_exit);
	/* int	examine; */
	/* int	cnt; */
	//@@@@@@@@@@@@@@
	t_cursor	head;
	t_stack		*input;
	char		*order;
	int	flag;

	input = NULL;
	if (ac < 2)
		return (ERROR);
	if (av_check(av, &input) == ERROR)
	{
		ft_putstr_fd("Error\n", 2);
		lst_clean(&input);
		return (ERROR);
	}
	stack_headset(&head, input);
	order = (char *)malloc(sizeof(char));
	ft_bzero(order, sizeof(char));

//-------------------------------------------------------
//	for (int i = 0; i < 7; i++)
//		px(&head, head.cur_a, head.cur_b, NULL);
//	debug_print(&head, 3);
//	wall_check_stack(&head, &order, 4, '2');
//	examine = next_check_nspot(&head, 4, '2');
//	wall_check_stack(&head, &order, 5, '0');
//	examine = next_check_nspot(&head, 5, '0');
//-------------------------------------------------------


	flag = 0;
	if (case_check(&head, &order) == ERROR && head.cnt_a > 5)
		stack_a_to_b(&head, &order, head.cnt_b, head.cnt_a, &flag);
//	debug_print(&head, 3);
//	printf("-------------------\n");
	/* examine = debug_sort_check(&head); */
//	stdio_test(&head, &order);
	/* cnt = order_print(order); */
	order_print(order);
	/* printf("-------------------\n"); */
	/* if (examine == ERROR) */
		/* printf("Total : %d || Sort : %s\n", cnt, "KO"); */
	/* else */
		/* printf("Total : %d || Sort : %s\n", cnt, "OK"); */
	stack_lstfclean(&head);
	free(order);
	return (SUCCESS);
}

void simple_order_print(char cur_order)
{
	if (!cur_order)
		write(1, "start!", 6);
	if (cur_order == BIT_PA)
		write(1, "pa", 2);
	else if (cur_order == (char)BIT_PB)
		write(1, "pb", 2);
	else if (cur_order == BIT_SA)
		write(1, "sa", 2);
	else if (cur_order == BIT_SB)
		write(1, "sb", 2);
	else if (cur_order == BIT_RA)
		write(1, "ra", 2);
	else if (cur_order == BIT_RB)
		write(1, "rb", 2);
	else if (cur_order == BIT_RRA)
		write(1, "rra", 3);
	else if (cur_order == BIT_RRB)
		write(1, "rrb", 3);
	write(1, "\n", 1);
}


void debug_print(t_cursor *head, int choice)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	write(1, "[COMMAND]\n", 10);
	/* if (cur_order) */
		/* simple_order_print(*cur_order); */
	write(1, "-----------------------", 23);
	ft_printf("\nstack A\t\tstack B\n");
	ft_printf("----------TOP----------\n");
	stack_a = head->cur_a;
	stack_b = head->cur_b;
	while (stack_a || stack_b)
	{
		if (!choice)
		{
			if (stack_a && stack_b)
				ft_printf("    %d\t\t  %d    \n", stack_a->idx, stack_b->idx);
			else if (stack_a && !stack_b)
				ft_printf("    %d\t\t     \n", stack_a->idx);
			else if (!stack_a && stack_b)
				ft_printf("      \t\t  %d    \n", stack_b->idx);
			else
				ft_printf("    \t\t    \n");
		}
		else if (choice == 1)
		{
			if (stack_a && stack_b)
				ft_printf("    %d|'%c'| \t  %d|'%c'|    \n", stack_a->idx, stack_a->spot, stack_b->idx, stack_b->spot);
			else if (stack_a && !stack_b)
				ft_printf("    %d|'%c'|\t     \n", stack_a->idx, stack_a->spot);
			else if (!stack_a && stack_b)
				ft_printf("    \t\t  %d|'%c'|    \n", stack_b->idx, stack_b->spot);
			else
				ft_printf("    \t\t    \n");
		}
		else if (choice == 3)
		{
			if (stack_a && stack_b)
				ft_printf("    %d|[%d]| \t  %d|[%d]|    \n", stack_a->idx, stack_a->tmp_idx, stack_b->idx, stack_b->tmp_idx);
			else if (stack_a && !stack_b)
				ft_printf("    %d|[%d]|\t     \n", stack_a->idx, stack_a->tmp_idx);
			else if (!stack_a && stack_b)
				ft_printf("    \t\t  %d|[%d]|    \n", stack_b->idx, stack_b->tmp_idx);
			else
				ft_printf("    \t\t    \n");
		}
		else
		{
			if (stack_a && stack_b)
				ft_printf("    %d(%d)\t  %d(%d)    \n", stack_a->num, stack_a->idx, stack_b->num, stack_b->idx);
			else if (stack_a && !stack_b)
				ft_printf("    %d(%d)\t     \n", stack_a->num, stack_a->idx);
			else if (!stack_a && stack_b)
				ft_printf("    \t\t  %d(%d)    \n", stack_b->num, stack_b->idx);
			else
				ft_printf("    \t\t    \n");
		}
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	stack_a = head->cur_a;
	stack_b = head->cur_b;
	ft_printf("----------BOT----------\n");
	ft_printf("   (%d)\t\t  (%d)  \n\n", head->cnt_a, head->cnt_b);
}

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

void only_exit(void)
{
	system("leaks push_swap");
}

int debug_sort_check(t_cursor *head)
{
	t_stack	*lst;

	if (head->cur_b)
		return (ERROR);
	lst = head->cur_a;
	while (lst->next)
	{
		if (lst->idx > lst->next->idx)
			return (ERROR);
		lst = lst->next;
	}
	return (SUCCESS);
}
