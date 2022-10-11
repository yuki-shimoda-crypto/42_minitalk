/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:54:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/11 19:54:51 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_check_over(int sign, long ans, char c)
{
	long	tmp;

	tmp = LONG_MAX / 10;
	if (sign == 1)
		c++;
	if (tmp < ans || (tmp == ans && LONG_MAX % 10 + 1 < c - '0'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	total;
	size_t	i;

	sign = 1;
	total = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (sign == 1 && ft_check_over(sign, total, str[i]))
			return ((int)(LONG_MAX));
		if (sign == -1 && ft_check_over(sign, total, str[i]))
			return ((int)(LONG_MIN));
		total = total * 10 + str[i] - '0';
		i++;
	}
	total *= sign;
	return ((int)total);
}
