#ifndef FF_H
#define FF_H
#include "../../../include/ft_printf.h"

void	default_mod_fF(t_param *param, unsigned int *all_len, t_flags *flag);

unsigned	int	count_num_f(double var);
double			ft_pow_lld(double num, unsigned int count);
unsigned	int	init_num_fF(t_pr *pr, t_param *param, t_flags *flag, double num);

#endif
