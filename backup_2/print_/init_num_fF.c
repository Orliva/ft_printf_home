#include "../include/ft_printf.h"

unsigned int count_int_part(long long int int_part)
{
	unsigned int len;

	len = 0;
	while (int_part / 10)
	{
		len++;
		int_part /= 10;
	}
	return (++len);
}

static	double ft_pow(double num, unsigned int presition)
{
	while (presition--)
		num *= 10;
	return (num);
}

unsigned int mal_num(unsigned int pres, long long int int_part, t_pr *pr)
{
	unsigned int len;

	if (pres > 0)
		pres++;
//	printf("count_int_part = %u\n", count_int_part(int_part));
	if (!(pr->num = (char *)malloc(sizeof(char) * ((len = count_int_part(int_part)
		+ pres + 1)))))
		ft_error_exit();
	return (--len);
}

void	init_num_fF(t_pr *pr, unsigned int presition, double num)
{
	unsigned long long int int_part;
	unsigned int len;

	int_part = (long long int)num;
//	printf("%d end\n", int_part);
	printf("presition = %u\n", presition);
	len = mal_num(presition, int_part, pr);
	printf("len = %u\n", len);
	pr->num[len--] = '\0';
	int_part = ft_pow(num, presition);
	printf("int_part = %llu\n", int_part);
	len = 0;
	while (int_part / 10)
	{
		if (presition > 0)
		{
			while (presition)
			{
				pr->num[len++] = (int_part % 10) + 48;
				int_part /= 10;
				presition--;
			}
			pr->num[len++] = '.';
		}
		pr->num[len++] = (int_part % 10) + 48;
		int_part /= 10;
	}
	write(1, "hfgd", 4);
	pr->num[len] = (int_part % 10) + 48;
	printf("pr->num = %s", pr->num);
}
