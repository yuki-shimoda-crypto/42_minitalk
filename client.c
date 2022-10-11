/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:43:43 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/11 20:13:30 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

void	send_sig(char const **argv, int pid)
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
			usleep(100);
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
		pid = atoi(argv[1]);
		if (pid <= 0 || kill(pid, 0) == -1)
			return (1);
		send_sig(argv, pid);
	}
	else
		return (1);
	return (0);
}
