#include "../ft_printf.h"

void	init_num_ouxX(t_pr *pr, unsigned long long int var)
{
	unsigned int	i;

	if (!(pr->num = (char *)malloc((sizeof (char)) * (count_num_pl(var) + 1))))
		ft_error_exit();
	i = 0;
	while (var)
	{
		pr->num[i++] = var % 10;
		var /= 10;
	}
}

void	init_num_di(t_pr *pr, long long int var)
{
	unsigned int	i;

	if (!(pr->num = (char *)malloc((sizeof (char)) * (count_num_pl(var) + 1))))
		ft_error_exit();
	i = 0;
	while (var)
	{
		pr->num[i++] = var % 10;
		var /= 10;
	}
}
