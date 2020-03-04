#include "inc/fF.h"

unsigned	int	count_num_f(double var)
{
	unsigned int count;

	count = 0;
	while ((int)(var / 10) != 0)//////+ добавить счет ширины
	{
		count++;
		var /= 10;
	}
	count++;//////Возможно при 0 тут будет косяк
	return (count);
}

double	ft_pow_lld(double num, unsigned int count)
{
	while (count)
	{
		num *= 10;
		count--;
	}
	return (num);
}
