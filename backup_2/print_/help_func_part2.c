#include "../include/ft_printf.h"

void	help_init_(unsigned int count, char *tmp, t_pr *pr)
{
	unsigned int	i;

	i = 0;
	while (i < count - 1)
	{
		tmp[i] = pr->num[i];
		i++;
	}
}

char	ft_letter(unsigned int num)
{
	if (num == 10)
		return ('a');
	if (num == 11)
		return ('b');
	if (num == 12)
		return ('c');
	if (num == 13)
		return ('d');
	if (num == 14)
		return ('e');
	return ('f');
}

void	init_num_16(t_pr *pr, unsigned long long int num)
{
	unsigned int	count;
	char	*tmp;

	if (!(pr->num = (char *)malloc(sizeof(char) * 1)))
		ft_error_exit();
	if (num == 0)
		arg_is_zero(pr);
	count = 1;
	while (num)
	{
		if (!(tmp = (char *)malloc((sizeof(char)) * (count + 1))))
			ft_error_exit();
		if (num % 16 < 10)
		{
			help_init_(count, tmp, pr);
			tmp[count - 1] = (num % 16) + 48;
			tmp[count] = '\0';
		}
		else
		{
			help_init_(count, tmp, pr);
			tmp[count - 1] = ft_letter((unsigned char)(num % 16));
			tmp[count] = '\0';
		}
		free(pr->num);
		pr->num = tmp;
		num /= 16;
		count++;
	}
}

void	init_num_8(t_pr *pr, unsigned long long num)
{
	unsigned int count;
	char	*tmp;

	if (!(pr->num = (char *)malloc(sizeof(char) * 1)))
		ft_error_exit();
	if (num == 0)
		arg_is_zero(pr);
	count = 1;
	while (num)
	{
		if (!(tmp = (char *)malloc((sizeof(char)) * (count + 1))))
			ft_error_exit();
		help_init_(count, tmp, pr);
		tmp[count - 1] = (num % 8) + 48;
		tmp[count] = '\0';
		free(pr->num);
		pr->num = tmp;
		num /= 8;
		count++;
	}
}
