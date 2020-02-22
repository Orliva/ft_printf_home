#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#define H "h"
#define HH "HH"
#define L_DOWN "l"
#define LL_DOWN "ll"
#define L_UP "L"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_flags
{
	int	sharp;
	int	zero;
	int	minus;
	int	plus;
	int	space;
}		t_flags;

typedef	struct	s_mod
{
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	L;
}		t_mod;

typedef	struct	s_param
{
	int	fd;
	char	*dup_format;
	char	*buff_dest;
	va_list	arg;
	int	len;
	char	*flag;
	int	width; ////may be used "int *width"
	int	presition;/////int *presition
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

#endif
