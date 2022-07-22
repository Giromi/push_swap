/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:41:59 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 19:44:25 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	debug_print(t_cursor *head, int choice);
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
	int	examine;
	//@@@@@@@@@@@@@@
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
	debug_print(&head, 3);
	stdio_input(&head);
	examine = debug_sort_check(&head);
	if (examine == ERROR)
		ft_putstr_fd("KO", 1);
	else
		ft_putstr_fd("OK", 1);
	stack_lstfclean(&head);
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


