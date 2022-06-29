/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:59:57 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/29 14:49:46 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_isminus(int c);
int ft_issp(int c);
void full_clean(char **array);
int	stack_lstadd_back(t_stack **lst, t_stack *new);
t_stack *stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst, int check);
void	*stack_lstfclean(t_stack **lst);
char	*ft_strchr_null(const char *s, int c);

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len);
size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize);
char	*ft_strjoin_addsp(char const *s1, char const *s2);
void ra(t_stack **lst);
void rra(t_stack **lst);

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

int main(int ac, char *av[])
{
	t_cursor	head;
	t_stack		*input;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*backup_a;
	t_stack		*backup_b;
	t_stack		*last;
	char		**array;
	char		*buf;
	int			i;
	char		c;

	/* ft_bzero(input, sizeof(t_stack)); */
	input = NULL;
	if (ac < 2)
	{
		printf("ERROR : less input\n");
		return (ERROR);
	}
	if (av_check(av, &input) == ERROR)
	{
		printf("ERROR : wrong input\n");
		stack_lstfclean(&input);
		return (ERROR);
	}

	/* last = stack_lstlast(input, '\0'); */
	/* last->next = first; */
	stack_a = input;
	stack_b = NULL;
	buf = (char *)malloc(sizeof(char) * 4);
	while (1)
	{
		ft_bzero(buf, sizeof(char) * 4);
		write(1, "command => ", 10);
		read(0, buf, 3);
		if (buf == ft_strnstr(buf, "00", 2))
			break ;
		else if (buf == ft_strnstr(buf, "ra", 2))
			ra(&stack_a);
		else if (buf == ft_strnstr(buf, "rra", 3))
			rra(&stack_a);
		else
			printf("command error\n");
		/* write(1, buf, 2); */
		/* write(1, "\n", 1); */

		/* if (ft_strnstr(buf, "ra", 2)) */

		/* else (ft_strnstr(buf, "ra", 2)) */
		write(1, "-----------------------", 23);
		printf("\nstack A\t\tstack B\n");
		printf("--TOP-------------TOP--\n");
		backup_a = stack_a;
		backup_b = stack_b;
		while (stack_a || stack_b)
		{
			if (stack_a)
			{
				c = stack_a->num + '0';
				write(1, "   ", 3);
				write(1, &c, 1);
				stack_a = stack_a->next;
			}
			else
				write(1, " ", 1);
			write(1, "\t\t", 1);
			if (stack_b)
			{
				c = stack_b->num + '0';
				write(1, "   ", 3);
				write(1, &c, 1);
				stack_b = stack_b->next;
			}
			else
				write(1, " ", 1);
			write(1, "\n", 1);
		}
		stack_a = backup_a;
		stack_b = backup_b;
		printf("--BOT-------------BOT--\n\n");
	}

	stack_lstfclean(&input);
	free(buf);
	/* system("leaks out --quit"); */

	return (0);
}


	/* while (1) */
	/* { */
		/* stack_print(); */
	/* } */
