#include "minitalk.h"

static int	ft_over_long(long long *num, int *minus, const char *str)
{
	if (*num > LONG_MAX / 10 && *minus == 1)
		return (1);
	if (*num == LONG_MAX / 10 && *str - '0' >= LONG_MAX % 10 && *minus == 1)
		return (1);
	if (*num > LONG_MIN / 10 * -1 && *minus == -1)
		return (1);
	if (*num == LONG_MIN / 10 * -1 && *str - '0' >= LONG_MIN % 10
		* -1 && *minus == -1)
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			minus;
	long long	total;
	size_t		i;

	minus = 1;
	total = 0;
	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (ft_over_long(&total, &minus, &str[i]) && minus == 1)
			return ((int)(LONG_MAX));
		if (ft_over_long(&total, &minus, &str[i]) && minus == -1)
			return ((int)(LONG_MIN));
		total = total * 10 + str[i] - '0';
		i++;
	}
	total *= minus;
	return ((int)total);
}