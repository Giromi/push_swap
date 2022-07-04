/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:59:57 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/29 07:49:24 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int ft_isminus(int c);
int ft_issp(int c);
void full_clean(char **array);

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len);
size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize);
char	*ft_strjoin_addsp(char const *s1, char const *s2);

char	**line_av(char **av)
{
	char	*str;
	char	*tmp;
	char	**tmp2;
	int		i;

	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	i = 1;
	while (av[i])
		str = ft_strjoin_addsp(str, av[i++]);
	tmp2 = ft_split(tmp, ' ');
	free(tmp);
	return (tmp2);
}

int av_check(char **split_av)
{
	/* int	num; */
	/* int	ea; */
	int i;
	int j;
	/* char	**tmp; */

	i = 0;
	while (split_av[i])
	{
		j = 0;
		while (split_av[i][j])
		{
			if (!(ft_isdigit(split_av[i][j])
				|| (j = 0 && split_av[i][j] == '-')))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (0);
		/* [> while (*av) <] */
		/* [> { <] */

			/* [> pos = ft_strchr(*av, ' '); <] */
			/* [> while (*(*av)++) <] */
			/* [> { <] */
					/* [> return (ERROR); <] */
			/* [> } <] */
			/* [> if (!pos) <] */
			/* [> break ; <] */
			/* [> if (!(ft_isdigit(**av) || ft_isminus(**av))) <] */
				/* [> return (ERROR); <] */
			/* [> num = ft_atoi(*av); <] */
			/* [> [> while (ft_isspmi(**av)) <] <] */
				/* [> [> *av++; <] <] */
			/* [> if (num != 0 || num == 0 && *(*av + 1) == '0') <] */
				/* [> printf("%d\n", num); <] */
			/* [> else <] */
				/* [> return (ERROR); <] */
			/* [> *av = pos; <] */

				/* [> return (ERROR); <] */


			/* [> while <] */
			/* [> if (num < 0) <] */
				/* [> len++; <] */

			/* [> stack_lstadd_back(input, stack_lstnew()) <] */
			/* [> *av++; <] */
		/* [> } <] */
	/* } */
	/* [> first = *input; <] */
	/* [> while (*input) <] */
	/* [> { <] */
		/* /* *input = *input->next; * */
		 /* * / */
	/* [> } <] */
	/* [> *input = first; <] */
	/* return (1); */
}

int main(int ac, char *av[])
{
	t_cursor	head;
	t_stack		*input;
	char		**array;
	int			i;

	if (ac < 2)
	{
		printf("ERROR : less input\n");
		return (ERROR);
	}

	/* input = NULL; */
	array = line_av(av);
	i = 1;
	while (array[i])
	{
		write(1, array[i], ft_strlen(array[i]));
		write(1, "\n", 1);
		i++;
	}

	if (av_check(array) == ERROR)
	{
		printf("ERROR : wrong input\n");
		full_clean(array);
		return (ERROR);
	}
	full_clean(array);
	/* system("leaks out --quit"); */
	return (0);
}


	/* while (1) */
	/* { */
		/* stack_print(); */
	/* } */
