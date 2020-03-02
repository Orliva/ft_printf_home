#include "inc/o.h"

unsigned	int	_is_presition_o(t_param *param)
{
	unsigned	int	i;

	i = 0;
	while (param->presition > param->count)
	{
		i += write(param->fd, "0", 1);
		param->presition--;
		if (param->width > 0)
			param->width--;
		param->len--;
	}
	return (i);
}

unsigned	int	_is_width_o(t_param *param, t_flags *flag)
{
	char tmp;
	unsigned	int	i;

	i = 0;
	tmp = flag->zero == 1 ? '0' : ' ';
	while (param->width > param->presition && param->width > param->count)
	{
		i += write(param->fd, &tmp, 1);
		param->width--;
		param->len--;
	}
	return (i);
}

unsigned	int	_is_sharp_o(t_param *param, t_flags *flag)
{
	unsigned	int i;

	i = 0;
	if (flag->sharp)
	{
		if (param->width > 0)
			param->width--;
		i += write(param->fd, "0", 1);
		param->len--;
	}
	return (i);
}
