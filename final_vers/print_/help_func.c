#include "../ft_printf.h"

void	ft_strlen_fd(char *print, t_param *param, unsigned int *all_len)
{
	while (*print)
	{
		write(param->fd, &*print++, 1);
		(*all_len)++;
	}
}

unsigned int count_num_min(unsigned long long int num)
{
	unsigned int count;

	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
//	count++;
	return (count);
}

unsigned int count_num_pl(long long int num)
{
	unsigned int count;

	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
//	count++;
	return (count);
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

unsigned int ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
