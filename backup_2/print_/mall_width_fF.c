#include "../include/ft_printf.h"

int	is_dot(t_pr *pr)
{
	unsigned int i;

	i = 0;
	while (pr->num[i])
	{
		if (pr->num[i++] == '.')
			return (1);
	}
	return (0);
}

void	mall_width_fF(t_param *param, unsigned int len, t_flags *flag, t_pr *pr)
{
	pr->print = NULL;
	if(len < param->presition && (is_dot(pr) == 1 || flag->sharp == 1))
		len = param->presition;
	if (flag->space == 1 || flag->plus == 1 || pr->sign == '-')
		len++;
	if (is_dot(pr) == 0 && flag->sharp == 1)
		len += param->presition + 1;
	if (len < param->width)
		len = param->width;

	if(!(pr->print = (char *)malloc(sizeof(char) * (len + 1))))
		ft_error_exit();
	printf("len = %u\n", len);
	param->len = len;
	pr->print[len] = '\0';
}
