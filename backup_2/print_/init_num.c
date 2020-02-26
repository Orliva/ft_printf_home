#include "../include/ft_printf.h"


void	init_num_u(t_pr *pr, unsigned long long int var)
{
	unsigned int	i;

	if (!(pr->num = (char *)malloc((sizeof (char)) * (count_num_pl(var) + 1))))
		ft_error_exit();
	i = 0;
	if (var == 0)
	{
		arg_is_zero(pr);
		i = 1;
	}
	while (var)
	{
		pr->num[i++] = (var % 10) + 48;
		var /= 10;
	}
	pr->num[i] = '\0';
}

static	void	low_zn_lld(char *str)
{
	str[18] = 9 + 48;
	str[17] = 2 + 48;
	str[16] = 2 + 48;
	str[15] = 3 + 48;
	str[14] = 3 + 48;
	str[13] = 7 + 48;
	str[12] = 2 + 48;
	str[11] = 0 + 48;
	str[10] = 3 + 48;
	str[9] = 6 + 48;
	str[8] = 8 + 48;
	str[7] = 5 + 48;
	str[6] = 4 + 48;
	str[5] = 7 + 48;
	str[4] = 7 + 48;
	str[3] = 5 + 48;
	str[2] = 8 + 48;
	str[1] = 0 + 48;
	str[0] = 8 + 48;
}

void	arg_is_zero(t_pr *pr)
{
	free(pr->num);
	if (!(pr->num = (char *)malloc(sizeof(char) * 2)))
		ft_error_exit();
	pr->num[0] = 0 + 48;
}

void	init_num_di(t_pr *pr, long long int var)
{
	unsigned int	i;

	if (!(pr->num = (char *)malloc((sizeof (char)) * (count_num_pl(var) + 1))))
		ft_error_exit();
	i = 0;
	if (var == 0)
	{
		arg_is_zero(pr);
		i = 1;
	}
	if (count_num_pl(var) == 19 && (var % 10) == -8)
	{
		low_zn_lld(pr->num);
		var = 0;
		i = 19;
	}
	var = var < 0 ? var * (-1) : var;
	while (var)
	{
		pr->num[i++] = (var % 10) + 48;
//		write(1, &pr->num[i-1], 1);
		var /= 10;
	}
	pr->num[i] = '\0';
//	printf("%c\n", pr->num[0]);
}
