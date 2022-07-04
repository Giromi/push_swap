/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:59:57 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/05 01:35:15 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulator.h"

int av_check(char **av, t_stack **input)
{
	int		num;
	char	*pos;
	char	*tmp;
	t_stack	*new;

	av++;
	while (*av)
	{
		while (**av)
		{

			while (ft_issp(**av))
				(*av)++;
			pos = ft_strchr_null(*av, ' ');
			tmp = *av;
			if (*tmp == '-')
				tmp++;
			while (tmp < pos)
			{
				if (!(ft_isdigit(*tmp)))
					return (ERROR);
				tmp++;
			}
			if (!**av)
				continue ;
			num = ft_atoi(*av);
			new = stack_lstnew(num);
			if (stack_lstadd_back(input, new) == ERROR)
			{
				free(new);
				return (ERROR);
			}
			*av = pos;
		}
		av++;
	}
	return (0);
}

void ft_info()
{
	printf("-----------------------");
	printf("< push swap simulator >");
	printf("-----------------------");
	printf("push swap 명령어 : ra, rb, pa, pb, sa, sb, ss, rra, rrb, rrr\n");
}


int main(int ac, char *av[])
{
	t_cursor	*head;
	t_stack		*input;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*buf;
	char		*order;

	order = (char *)malloc(sizeof(char));
	ft_bzero(order, sizeof(char));
	input = NULL;
	if (ac < 2)
	{
		printf("ERROR : less input\n");
		return (ERROR);
	}
	if (av_check(av, &input) == ERROR)
	{
		printf("ERROR : wrong input\n");
		lst_clean(&input);
		return (ERROR);
	}
	stack_circle(&input);
	head = (t_cursor *)malloc(sizeof(t_cursor));
	head->cur_a = input;
	head->cur_b = NULL;
	buf = (char *)malloc(sizeof(char) * 5);
	while (1)
	{
		write(1, "-----------------------", 23);
		printf("\nstack A\t\tstack B\n");
		printf("----------TOP----------\n");
		stack_a = head->cur_a;
		stack_b = head->cur_b;
		while (stack_a || stack_b)
		{
			if (stack_a && stack_b)
				printf("    %d\t\t  %d    \n", stack_a->num, stack_b->num);
			else if (stack_a && !stack_b)
				printf("    %d\t\t     \n", stack_a->num);
			else if (!stack_a && stack_b)
				printf("     \t\t  %d    \n", stack_b->num);
			else
				printf("    \t\t    \n");
			if (stack_a)
				stack_a = stack_a->next;
			if (stack_b)
				stack_b = stack_b->next;
		}
		stack_a = head->cur_a;
		stack_b = head->cur_b;
		printf("----------BOT----------\n\n");

		ft_bzero(buf, sizeof(char) * 5);
		write(1, "command => ", 11);
		read(0, buf, 4);
		write(1, buf, 4);
		if (ft_strnstr(buf, "00\n", 3))
			break ;
		else if (ft_strnstr(buf, "00\n", 3))
			ft_info();
		else if (ft_strnstr(buf, "-1\n", 3))
			order = ft_charundo(order);
		else if (ft_strnstr(buf, "pa\n", 3))
			order = pa(head, order);
		else if (ft_strnstr(buf, "pb\n", 3))
			order = pb(head, order);
		else if (ft_strnstr(buf, "sa\n", 3))
			order = sa(head, order);
		else if (ft_strnstr(buf, "sb\n", 3))
			order = sb(head, order);
		else if (ft_strnstr(buf, "ra\n", 3))
			order = ra(head, order);
		else if (ft_strnstr(buf, "rb\n", 3))
			order = rb(head, order);
		else if (ft_strnstr(buf, "rra\n", 4))
			order = rra(head, order);
		else if (ft_strnstr(buf, "rrb\n", 4))
			order = rrb(head, order);
		else if (ft_strnstr(buf, "ss\n", 3))
			order = ss(head, order);
		else if (ft_strnstr(buf, "rr\n", 3))
			order = rr(head, order);
		else if (ft_strnstr(buf, "rrr\n", 4))
			order = rrr(head, order);
		else
			printf("noting\n");
	}
	free(buf);
	stack_lstfclean(head);
	printf("-----------------------\n");
	order_print(order);
	free(order);
	return (0);
}
