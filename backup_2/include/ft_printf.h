#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#define H 1
#define HH 2
#define L_DOWN 3
#define LL_DOWN 4
#define L_UP 5
#define NONE_MODE 0
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "../print_/di/di.h"
#include "../print_/o/o.h"
#include "../print_/u/u.h"
#include "../print_/xX/xX.h"
#include "../print_/scp/scp.h"
//#include "../print_/f/f.h"

int	ft_printf(const char *format, ...);
int	init_param(t_param *param, unsigned int *all_len);
void	is_flag(t_param *param);
void	is_width(t_param *param);
void	is_presition(t_param *param);
void	is_mod(t_param *param);
void	is_type(t_param *param);
int	is_spesific_symb(t_param *param, unsigned int *all_len);

int	compare(char *s1, char *s2);
unsigned int	ft_strlen(char *str);
void	ft_error_exit();
void	free_all(t_param *param);////delete
void	ft_putstr_fd(char *print, t_param *param, unsigned int *all_len);
unsigned	int	count_num_min(unsigned long long int num, t_param *param);
unsigned	int	count_num_pl(long long int num);

short	int	choice_mod(t_param *param);
void	di_func(t_param *param, unsigned int *all_len, t_flags *flag);
void	ouxX_func(t_param *param, unsigned int *all_len, t_flags *flag);
void	fF_func(t_param *param, unsigned int *all_len, t_flags *flag);
void	c_func(t_param *param, unsigned int *all_len, t_flags *flag);
void	p_func(t_param *param, unsigned int *all_len, t_flags *flag);
void	flag_reset(t_flags *flag);
void	init_flag(t_param *param, t_flags *flag);
void	type_print(t_param *param, unsigned int *all_len);

#endif
