/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/28 22:55:32 by minsuki2         ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_cursor head;

	if (ac < 2)
	{
		ft_printf("ERROR : less input")
		return (ERROR);
	}
	if (av_check(av) == ERROR)
	{
		ft_printf("ERROR : wrong input")
		return (ERROR);
	}

	if (nord_list(av, &set) == ERROR)
		return (0);
	if (ac % 2 == 0)
	{
		if (ac == 2)
			two_input(av);
	}
	else
		printf("odd");

	printf("here");
	return (0);
}
