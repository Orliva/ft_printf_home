#include "../ft_printf.h"


void	init_num_u(t_pr *pr, unsigned long long int var)
{
	unsigned int	i;

	if (!(pr->num = (char *)malloc((sizeof (char)) * (count_num_pl(var) + 1))))
		ft_error_exit();
	i = 0;
	while (var)
	{
		pr->num[i++] = (var % 10) + 48;
		var /= 10;
	}
	pr->num[i] = '\0';
}

void	init_num_di(t_pr *pr, long long int var)
{
	unsigned int	i;

	if (!(pr->num = (char *)malloc((sizeof (char)) * (count_num_pl(var) + 1))))
		ft_error_exit();
	i = 0;
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
