/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:22:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/29 08:30:19 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stack_lstnew(int num)
{
	nord_lst	*new:


	new = malloc(sizeof(nord_lst));
	if (!new)
		return (NULL);
	new->num = num;
	new->prev = behind;
	new->next = NULL;
	return (new);
}

t_stack *stack_lstadd_back

int ft_isspace(int c)
{
	return (c == ' ');
}
