/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:59:57 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/01 05:14:01 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_isminus(int c);
int		ft_issp(int c);
void	full_clean(char **array);
int		stack_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst, int check);
void	lst_clean(t_stack **lst);
void	stack_lstfclean(t_cursor *head);
char	*ft_strchr_null(const char *s, int c);

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len);
size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize);
char	*ft_strjoin_addsp(char const *s1, char const *s2);
void	stack_circle(t_stack **lst);
void	ra(t_cursor *head);
void	rra(t_cursor *head);
void	pb(t_cursor *head);
void sa(t_cursor *head);

void rb(t_cursor *head);
void rrb(t_cursor *head);
void rr(t_cursor *head);
void rrr(t_cursor *head);

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
	t_cursor	*head;
	t_stack		*input;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*backup_a;
	t_stack		*backup_b;
	t_stack		*last;
	ssize_t		rd;
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
		lst_clean(&input);
		return (ERROR);
	}
	stack_circle(&input);
	head = (t_cursor *)malloc(sizeof(t_cursor));
	head->cur_a = input;
	head->cur_b = NULL;
	buf = (char *)malloc(sizeof(char) * 4);
	while (1)
	{
		/* head->b = stack_a; */
		/* write(1, buf, 2); */
		/* write(1, "\n", 1); */

		/* if (ft_strnstr(buf, "ra", 2)) */

		/* else (ft_strnstr(buf, "ra", 2)) */
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

		ft_bzero(buf, sizeof(char) * 4);
		write(1, "command => ", 11);
		rd = read(0, buf, 4);
		if (buf == ft_strnstr(buf, "00", 2))
			break ;
		else if (buf == ft_strnstr(buf, "ra", 2))
			ra(head);
		else if (buf == ft_strnstr(buf, "rb", 2))
			rb(head);
		else if (buf == ft_strnstr(buf, "rr", 2))
			rr(head);
		else if (buf == ft_strnstr(buf, "rra", 3))
			rra(head);
		else if (buf == ft_strnstr(buf, "rrb", 3))
			rrb(head);
		else if (buf == ft_strnstr(buf, "rrr", 3))
			rrr(head);
		else if (buf == ft_strnstr(buf, "sa", 3))
			sa(head);
		else if (buf == ft_strnstr(buf, "pb", 3))
			pb(head);
		else
			printf("noting\n");
	}
	free(buf);
	stack_lstfclean(head);
	/* system("leaks out --quit"); */

	return (0);
}


	/* while (1) */
	/* { */
		/* stack_print(); */
	/* } */
