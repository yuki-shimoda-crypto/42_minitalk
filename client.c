/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:43:43 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/12 15:39:39 by yshimoda         ###   ########.fr       */
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

static int	ft_atoi(const char *str)
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

static void	send_sig(char const **argv, int pid)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (1)
	{
		j = 0;
		while (j != 8)
		{
			c = argv[2][i];
			c = (c >> (7 - j)) & 1;
			if (c)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(500);
		}
		if (!argv[2][i])
			break ;
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0 || kill(pid, 0) == -1)
			return (1);
		send_sig(argv, pid);
	}
	else
		return (1);
	return (0);
}
