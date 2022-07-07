/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/07 22:06:15 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static input_check_make(int ac, char *av[]) */
/* { */
	/* return */
/* } */


int	two_input(nord *first)
{
}

int nord_list(char *av)
{
	int i;

	if (!av && !*av)
		return (ERROR);
	if (!set)
		return (NULL)

	i = 0;
	while (av[i])
	{
		while (av[i][j])
			if()

		nord
		i++
	}
}

	ft_bzero(&set, sizeof(nord))

int av_check(char **input)
{
	t_stack
	while (*input)
	{
		while (**input)
		{
			if (!(ft_isdigit(**input) && ft_isspace(**input)))
				return (ERROR);


			(**input)++;
		}
		(*input)++;
	}
}
void debug_print()
{
	t_stack		*stack_a;
	t_stack		*stack_b;
		write(1, "-----------------------", 23);
		ft_printf("\nstack A\t\tstack B\n");
		ft_printf("----------TOP----------\n");
		stack_a = head->cur_a;
		stack_b = head->cur_b;
		while (stack_a || stack_b)
		{
			if (stack_a && stack_b)
				ft_printf("    %d\t\t  %d    \n", stack_a->num, stack_b->num);
			else if (stack_a && !stack_b)
				ft_printf("    %d\t\t     \n", stack_a->num);
			else if (!stack_a && stack_b)
				ft_printf("     \t\t  %d    \n", stack_b->num);
			else
				ft_printf("    \t\t    \n");
			if (stack_a)
				stack_a = stack_a->next;
			if (stack_b)
				stack_b = stack_b->next;
		}
		stack_a = head->cur_a;
		stack_b = head->cur_b;
		ft_printf("----------BOT----------\n\n");
}

void ft_error_exit();
{
	ft_printf(":wq
			[U[

	exit(1);
}

int main(int ac, char *av[])
{
	t_cursor	*head;
	t_stack		*input;
	char		*buf;
	char		*order;

	order = (char *)malloc(sizeof(char));
	ft_bzero(order, sizeof(char));
	input = NULL;
	if (ac < 2)
		ft_error_exit();
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	if (av_check(av, &input) == ERROR)
	{
		ft_printf("Error : wrong input\n");
		lst_clean(&input);
		return (ERROR);
	}
	stack_circle(&input);
	head = (t_cursor *)malloc(sizeof(t_cursor));
	head->cur_a = input;
	head->cur_b = NULL;
	buf = (char *)malloc(sizeof(char) * 5);

	free(buf);
	stack_lstfclean(head);
	ft_printf("-----------------------\n");
	order_print(order);
	free(order);
	return (0);
}
