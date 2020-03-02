#ifndef DI_H
#define DI_H
#include "../../../include/ft_printf.h"

void	default_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void	h_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void	hh_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void	l_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void	ll_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
unsigned	int	init_num_di(t_pr *pr, long long int var, t_flags *flag, t_param *param);
unsigned	int	_is_presition_di(t_param *param);
unsigned	int	_is_width_di(t_pr *pr, t_param *param, t_flags *flag);
unsigned	int	_is_sign_space_di(t_pr *pr, t_param *param, t_flags *flag);

#endif
