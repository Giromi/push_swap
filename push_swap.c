/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/22 21:04:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	whether_a_b(char c)
{
	char	set_a;
	char	set_b;

	set_a = (char)(BIT_PA | BIT_SA | BIT_RA | BIT_RRA);
	set_b = (char)(BIT_PB | BIT_SB | BIT_RB | BIT_RRB);
	if (c & set_a)
		write(1, "a", 1);
	else if (c & set_b)
		write(1, "b", 1);
}

static void	print_order(char *result)
{
	int	i;
	int	old_i;

	i = 0;
	while (result[i++])
	{
		old_i = i;
		if ((result[i - 1] | result[i]) == (BIT_SA | BIT_SB) && ++i)
			ft_putstr_fd("ss", 1);
		else if ((result[i - 1] | result[i]) == (BIT_RA | BIT_RB) && ++i)
			ft_putstr_fd("rr", 1);
		else if ((result[i - 1] | result[i]) == (BIT_RRA | BIT_RRB) && ++i)
			ft_putstr_fd("rrr", 1);
		else if (result[i - 1] & (BIT_PA | BIT_PB))
			ft_putstr_fd("p", 1);
		else if (result[i - 1] & (BIT_SA | BIT_SB))
			ft_putstr_fd("s", 1);
		else if (result[i - 1] & (BIT_RA | BIT_RB))
			ft_putstr_fd("r", 1);
		else if (result[i - 1] & (BIT_RRA | BIT_RRB))
			ft_putstr_fd("rr", 1);
		if (old_i == i)
			whether_a_b(result[i - 1]);
		ft_putchar_fd('\n', 1);
	}
}

int	main(int ac, char *av[])
{
	t_cursor	head;
	t_stack		*input;
	int			flag;

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
	flag = 0;
	if (case_check(&head) == ERROR && head.cnt_a > 5)
		stack_a_to_b(&head, head.cnt_b, head.cnt_a, &flag);
	if (head.order)
		print_order(head.order);
	stack_lstfclean(&head);
	return (SUCCESS);
}
