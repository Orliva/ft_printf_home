#include "../include/ft_printf.h"

static	void	pf_atoi(t_param *param)
{
	int	n;

	n = 10;
	param->fF_presi = 0;
	while (*param->dup_format >= '0' && *param->dup_format <= '9')
	{
		param->fF_presi = 1;
		param->presition = (param->presition * n) + (*param->dup_format - '0');
		param->dup_format++;
	}
}
void	is_presition(t_param *param)
{
	param->presition = 0;
	if (*param->dup_format >= '0' && *param->dup_format <= '9')
		pf_atoi(param);
}
