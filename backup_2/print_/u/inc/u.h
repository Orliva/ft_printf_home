#ifndef	U_H
#define U_H
#include "../../../include/ft_printf.h"

void	default_mod_u(t_param *param, unsigned int *all_len, t_flags *flag);
void	h_mod_u(t_param *param, unsigned int *all_len, t_flags *flag);
void	hh_mod_u(t_param *param, unsigned int *all_len, t_flags *flag);
void	l_mod_u(t_param *param, unsigned int *all_len, t_flags *flag);
void	ll_mod_u(t_param *param, unsigned int *all_len, t_flags *flag);

unsigned	int	init_num_u(unsigned long long int var, t_flags *flag, t_param *param);
unsigned	int	_is_width_u(t_param *param, t_flags *flag);
unsigned	int	_is_presition_u(t_param *param);

#endif
