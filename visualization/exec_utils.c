/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:16:28 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/29 15:00:34 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/* t_stack	*ft_lstlast(t_stack *lst) */
/* { */
	/* if (!lst) */
		/* return (NULL); */
	/* while (lst->next) */
		/* lst = lst->next; */
	/* return (lst); */
/* } */

/* void	stack_lstadd_back(t_stack **lst, t_stack *new) */
/* { */
	/* t_stact	*tmp; */

	/* if (!lst || !new) */
		/* return ; */
	/* if (!*lst) */
		/* *lst = new; */
	/* else */
	/* { */
		/* tmp = stack_lstlast(*lst); */
		/* tmp->next = new; */
	/* } */
/* } */

int ft_isminus(int c)
{
	return (c == '-');
}

int ft_issp(int c)
{
	return (c == ' ');
}

void full_clean(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	if (array)
		free(array);
	printf("Finished full_clean\n");
}

size_t	ft_strlcat_known(char *dst, size_t dst_len, char const *src,
		size_t src_len)
{
	size_t	dstsize;

	src_len = ft_strlen(src);
	dstsize = src_len + dst_len + 1;
	dst[dstsize - 1] = '\0';
	while (dstsize-- - 1 > dst_len)
		dst[dstsize - 1] = src[dstsize - dst_len - 1];
	return (dst_len + src_len);
}

size_t	ft_strlcpy_known(char *dst, char const *src, size_t len
		, size_t dstsize)
{
	if (dstsize > 0)
	{
		if (len + 1 < dstsize)
			dstsize = len + 1;
		dst[dstsize - 1] = '\0';
		while (dstsize-- - 1)
			dst[dstsize - 1] = src[dstsize - 1];
	}
	return (len);
}

char	*ft_strjoin_addsp(char const *s1, char const *s2)
{
	char	*pt;
	size_t	size;

	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size =  s1_len + s2_len + 2;
	pt = (char *)malloc(sizeof(char) * size);
	if (!pt)
		return (NULL);
	pt[size - 1] = ' ';
	ft_strlcpy_known(pt, s1, s1_len, size);
	ft_strlcat_known(pt, s1_len, s2, s2_len);
	return (pt);
}

char	*ft_strchr_null(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return ((char *)s + i);
}

t_stack	*stack_lstlast(t_stack *lst, int check)
{
	t_stack	*first;

	if (!lst || (check && lst->num == check))
		return (NULL);
	while (lst->next)
	{
		if (check && lst->next->num == check)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}



t_stack *stack_lstnew(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

int	stack_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return (ERROR);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = stack_lstlast(*lst, new->num);
		if (!tmp)
			return (ERROR);
		tmp->next = new;
	}
	return (SUCCESS);
}

int	stack_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!lst || !new)
		return (ERROR);
	first = stack_lstnew(new->num);
	free(new);
	if (!*lst)
		first->next = NULL;
	else
		first->next = *lst;
	*lst = first;
	return (SUCCESS);
}

void	*stack_lstfclean(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	while (*lst)
	{
		tmp = (*lst);
		*lst = (*lst)->next;
		free(tmp);
		/* free((*lst)->content); */
	}
	return (NULL);
}



void ra(t_stack **lst)
{
	t_stack	*last;

	last = *lst;
	*lst = (*lst)->next;
	stack_lstadd_back(lst, last);
	last->next = NULL;
}

void rra(t_stack **lst)
{
	t_stack	*last;

	last = stack_lstlast(*lst, '\0');
	stack_lstadd_front(lst, last);
}

