#ifndef SCP_H
#define SCP_H
#include "../../../include/ft_printf.h"


void	default_mod_p(t_param *param, unsigned int *all_len, t_flags *flag);
void	default_mod_c(t_param *param, unsigned int *all_len, t_flags *flag);
void	default_mod_s(t_param *param, unsigned int *all_len, t_flags *flag);

void	init_num_c(t_flags *flag, t_param *param, unsigned int *all_len, unsigned char num);
void	init_num_s(t_flags *flag, t_param *param, unsigned int *all_len, char *num);
unsigned	int	init_num_16_p(unsigned long long int var, t_flags *flag, t_param *param);
unsigned	int	print_num_p(t_param *param, unsigned long long int var);

unsigned	int	_is_presition_p(t_param *param);
unsigned	int	_is_width_p(t_param *param, t_flags *flag);
unsigned	int	_is_sharp_p(t_param *param, t_flags *flag);

#endif
