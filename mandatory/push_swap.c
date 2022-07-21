/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/21 13:29:52 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void debug_print(t_cursor *head, int choice);

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
		while (1)
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
	t_cursor	head;
	t_stack		*input;
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
	debug_print(&head, 1);
	flag = 0;
	if (case_check(&head) == ERROR && head.cnt_a > 5)
		stack_a_to_b(&head, head.cnt_b, head.cnt_a, &flag);
	order_print(head.order);
	stack_lstfclean(&head);
	system("leaks push_swap");
	return (SUCCESS);
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
	
