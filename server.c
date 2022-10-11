/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:43:45 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/11 20:19:47 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	ft_sig1(int signal)
{
	static int	i;
	static int	c;

	i++;
	if (signal == SIGUSR1)
		c = (c * 2) + 1;
	else
		c = (c * 2) + 0;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	sigset_t	set;

	printf("%d\n", getpid());
	if (sigemptyset(&set))
		return (1);
	if (sigaddset(&set, SIGUSR1))
		return (1);
	if (sigaddset(&set, SIGUSR2))
		return (1);
	signal(SIGUSR1, &ft_sig1);
	signal(SIGUSR2, &ft_sig1);
	while (1)
		pause();
	return (0);
}
