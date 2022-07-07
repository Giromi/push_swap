/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:17:04 by minsuki2          #+#    #+#             */
/*   Updated: 2022/07/05 09:03:14 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulator.h"

static	unsigned int	make_max(int sign)
{
	if (sign == -1)
		return (VAL_INT_MIN);
	return (VAL_INT_MAX);
}

static	int	plma_check(const char *sign, int *sign_ptr)
{
	size_t	n;

	n = 0;
	if (*sign == '+' || *sign == '-')
		if (n++ + 1 && *sign == '-')
			*sign_ptr *= -1;
	return (n);
}

int	ft_simple_atoi(const char *str)
{
	int				i;
	int				c;
	int				sign;
	unsigned int	num;
	unsigned int	over_value;

	num = 0;
	sign = 1;
	i = plma_check(str, &sign);
	over_value = make_max(sign);
	while (ft_isdigit(str[i]) && str[i])
	{
		c = str[i] - '0';
		if ((num > (over_value / 10)) || ((num == (over_value / 10))
					&& (c > (int)(over_value % 10))))
			return (over_value + sign);
		num = num * 10 + c;
		i++;
	}
	return (sign * num);
}
