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
	unsigned char	c;

	i = 0;
	pid = atoi(argv[1]);
	// printf("%d\n", pid);
	// printf("%d\n", argc);
	if (pid <= 0)
		return (1);
	if (argc == 3)
	{
		while (1)
		{
			j = 0;
			while (j != 8)
			{
				c = argv[2][i];
				c = c >> (7 - j);
				if (c)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				j++;
				usleep(10000);
			}
			// printf("%c\n", c);
			if (!argv[2][i])
				break ;
			i++;
		}
	}
	else
		return (1);
	return (0);
}
