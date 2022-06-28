/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:22:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/06/06 19:32:18 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

nord_lst *ft_nord_lstnew(nord_lst *behind, int num)
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
