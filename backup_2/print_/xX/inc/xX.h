#ifndef	XX_H
#define XX_H
#include "../../../include/ft_printf.h"


void	default_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag);
void	h_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag);
void	hh_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag);
void	l_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag);
void	ll_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag);

unsigned	int	init_num_16_xX(unsigned long long int var, t_flags *flag, t_param *param);
unsigned	int	print_num_xX(t_param *param, unsigned long long int var);
unsigned	int	_is_presition_xX(t_param *param);
unsigned	int	_is_width_xX(t_param *param, t_flags *flag);
unsigned	int	_is_sharp_xX(t_param *param, t_flags *flag);



#endif
