#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"


int main(int argc, char const *argv[])
{
	size_t	i;
	size_t	j;
	int		pid;
	char	c;

	i = 0;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (pid <= 0 || kill(pid, 0) == -1)
			return (1);
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
	else
		return (1);
	return (0);
}
