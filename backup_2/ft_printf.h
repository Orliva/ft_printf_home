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

typedef	struct	s_pr
{
	char *print;
	char *num;
	char sign;
}		t_pr;

typedef	struct	s_flags
{
	int	sharp;
	int	zero;
	int	minus;
	int	plus;
	int	space;
}		t_flags;

typedef	struct	s_param
{
	int	fd;
	char	*dup_format;
	char	*buff_dest;
	va_list	arg;
	unsigned int	len;
	char	*flag;
	unsigned int	width; ////may be used "int *width"
	unsigned int	presition;/////int *presition
	char	*mod; ////h, hh, l, ll
	char	type; ///diouxX (h, hh, l, ll), f (l , L)
	char	spesific_symb;

}		t_param;

int	ft_printf(const char *format, ...);
void	init_param(t_param *param, unsigned int *all_len);
void	is_flag(t_param *param);
void	is_width(t_param *param);
void	is_presition(t_param *param);
void	is_mod(t_param *param);
void	is_type(t_param *param);
int	is_spesific_symb(t_param *param, unsigned int *all_len);

int	compare(char *s1, char *s2);
unsigned int	ft_strlen(char *str);
void	ft_error_exit();
void	free_all(t_param *param);

void    di_func(t_param *param, unsigned int *all_len, t_flags *flag);
void    ouxX_func(t_param *param, unsigned int *all_len, t_flags *flag);
void    diouxX_print(t_param *param, unsigned int *all_len);
void    init_flag(t_param *param, t_flags *flag);
void    final_print(t_pr *pr, t_param *param, unsigned int *all_len, t_flags *flag);
void    left_pos(t_pr *pr, t_param *param, t_flags *flag);
void    right_pos(t_pr *pr, t_param *param, t_flags *flag);
void    _is_sign_space(t_pr *pr, t_param *param, t_flags *flag);
void    _is_sharp(char *print, t_param *param, t_flags *flag);
void    _is_width(char *print, t_param *param, t_flags *flag, unsigned int val);
void    _is_presition(char *print, t_param *param, t_flags *flag, unsigned int val);
void    ft_putstr_fd(char *print, t_param *param, unsigned int *all_len);
unsigned int count_num_min(unsigned long long int num, t_param *param);
unsigned int count_num_pl(long long int num);
void    init_num_di(t_pr *pr, long long int var);
void	init_num_16(t_pr *pr, unsigned long long int num);
void	init_num_8(t_pr *pr, unsigned long long int num);
void    init_num_u(t_pr *pr, unsigned long long int var);
char    *mall_width(t_param *param, unsigned int len, t_flags *flag, t_pr *pr);
short int choice_mod(t_param *param);
void    hh_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag);
void    hh_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void    h_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag);
void    h_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void    ll_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag);
void    ll_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void    l_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag);
void    l_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void    default_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag);
void    default_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void    print_param(t_param *param, unsigned int *all_len);
void	upper_case_pf(char *str);

#endif
