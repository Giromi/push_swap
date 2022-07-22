/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 19:44:14 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void debug_print(t_cursor *head, int choice);
#include <stdio.h>
/* #include "../libft/libft.h" */

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

static int	av_check(char **av, t_stack **input)
{
	int		num;
	char	flag;
	t_stack	*new;

	while (*(++av))
	{
		flag = '\0';
		while (1)
		{
			while (**av == ' ')
				(*av)++;
			if (flag && !**av)
				break ;
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

int follow_command_len3(t_cursor *head)
{
	if (ft_strnstr(head->order, "pa\n", 3))
		return (px(head, head->cur_b, head->cur_a));
	else if (ft_strnstr(buf, "pb\n", 3))
		return (px(head, head->cur_a, head->cur_b));
	else if (ft_strnstr(buf, "sa\n", 3))
		return (sx(head, head->cur_a));
	else if (ft_strnstr(buf, "sb\n", 3))
		return (sx(head, head->cur_b));
	else if (ft_strnstr(buf, "ra\n", 3))
		return (rx(head, head->cur_a);
	else if (ft_strnstr(buf, "rb\n", 3))
		return (rx(head, head->cur_b);
	else if (ft_strnstr(buf, "ss\n", 3))
	{
		return (sx(head, head->cur_a));
		return (sx(head, head->cur_b));
	}
	else if (ft_strnstr(buf, "rr\n", 3))
	{
		return (rx(head, head->cur_a));
		return (rx(head, head->cur_b));
	}
	return (ERROR);
}

int follow_command_len4(t_cursor *head)
{
	if (ft_strnstr(buf, "rra\n", 4))
		return (rrx(head, head->cur_a);
	else if (ft_strnstr(buf, "rrb\n", 4))
		return (rrx(head, head->cur_b);
	else if (ft_strnstr(buf, "rrr\n", 4))
	{
		return (rrx(head, head->cur_a);
		return (rrx(head, head->cur_b);
	}
	return (ERROR);
}

static int stdio_input(t_cursor *head)
{
	int		i;
	int		check;

	while (1)
	{
		check = ERROR;
		head->order = get_next_line(0);
		if (!head->order)
			break ;
		while (head->order[i] && head->order[i] != '\n')
			i++;
		if (head->order[i] == '\0')
			return (ERROR);
		if (check == ERROR)
			check = follow_command_len3(head);
		if (check == ERROR)
			check = follow_command_len4(head);
		if (check == ERROR)
			return (ERROR);
		free(head->order);
	}
	/* ft_strchr_null() */
	/* while (1) */
	/* { */

		/* ft_bzero(buf, sizeof(char) * 5); */
		/* write(1, "input => ", 9); */
		/* read(0, buf, 4); */
		/* if (!order) */
			/* printf("isproblem\n"); */
	/* } */
	return (SUCCESS);
}

int	main(int ac, char *av[])
{
	t_cursor	head;
	t_stack		*input;

	input = NULL;
	if (ac < 2)
		return (ERROR);
	if (av_check(av, &input) == ERROR)
	{
		ft_putstr_fd("Error\n", 2);
		lst_clean(&input);
		return (ERROR);
	}
	stack_head_set(&head, input);
	debug_print(&head, 1);
	if (stdio_input(&head) == ERROR)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (debug_sort_check(&head) == SUCCESS)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	debug_print(&head, 1);
	stack_lstfclean(&head);
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
	printf("\nstack A\t\tstack B\n");
	printf("----------TOP----------\n");
	stack_a = head->cur_a;
	stack_b = head->cur_b;
	while (stack_a || stack_b)
	{
		if (!choice)
		{
			if (stack_a && stack_b)
				printf("    %d\t\t  %d    \n", stack_a->idx, stack_b->idx);
			else if (stack_a && !stack_b)
				printf("    %d\t\t     \n", stack_a->idx);
			else if (!stack_a && stack_b)
				printf("      \t\t  %d    \n", stack_b->idx);
			else
				printf("    \t\t    \n");
		}
		else if (choice == 1)
		{
			if (stack_a && stack_b)
				printf("    %d|'%c'| \t  %d|'%c'|    \n", stack_a->idx, stack_a->spot, stack_b->idx, stack_b->spot);
			else if (stack_a && !stack_b)
				printf("    %d|'%c'|\t     \n", stack_a->idx, stack_a->spot);
			else if (!stack_a && stack_b)
				printf("    \t\t  %d|'%c'|    \n", stack_b->idx, stack_b->spot);
			else
				printf("    \t\t    \n");
		}
		else if (choice == 3)
		{
			if (stack_a && stack_b)
				printf("    %d|[%d]| \t  %d|[%d]|    \n", stack_a->idx, stack_a->tmp_idx, stack_b->idx, stack_b->tmp_idx);
			else if (stack_a && !stack_b)
				printf("    %d|[%d]|\t     \n", stack_a->idx, stack_a->tmp_idx);
			else if (!stack_a && stack_b)
				printf("    \t\t  %d|[%d]|    \n", stack_b->idx, stack_b->tmp_idx);
			else
				printf("    \t\t    \n");
		}
		else
		{
			if (stack_a && stack_b)
				printf("    %d(%d)\t  %d(%d)    \n", stack_a->num, stack_a->idx, stack_b->num, stack_b->idx);
			else if (stack_a && !stack_b)
				printf("    %d(%d)\t     \n", stack_a->num, stack_a->idx);
			else if (!stack_a && stack_b)
				printf("    \t\t  %d(%d)    \n", stack_b->num, stack_b->idx);
			else
				printf("    \t\t    \n");
		}
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	stack_a = head->cur_a;
	stack_b = head->cur_b;
	printf("----------BOT----------\n");
	printf("   (%d)\t\t  (%d)  \n\n", head->cnt_a, head->cnt_b);
}

void only_exit(void)
{
	system("leaks push_swap");
}
