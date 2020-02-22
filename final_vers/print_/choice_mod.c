#include "../ft_printf.h"

short int choice_mod(t_param *param)
{
	if (param->mod[0] != '\0')
	{
		if (compare("h", param->mod) == 0)
			return (H);
		if (compare("hh", param->mod) == 0)
			return (HH);
		if (compare("l", param->mod) == 0)
			return (L_DOWN);
		if (compare("ll", param->mod) == 0)
			return (LL_DOWN);
		if (compare("L", param->mod) == 0)
			return (L_UP);
	}
//	write(1, "QQQWWW", 6);
	return (NONE_MODE);
}
