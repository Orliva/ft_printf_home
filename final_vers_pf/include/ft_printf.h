/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:32:09 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:34:34 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define H 1
# define HH 2
# define L_DOWN 3
# define LL_DOWN 4
# define L_UP 5
# define NONE_MODE 0
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "struct.h"
# include "../print_/di/inc/di.h"
# include "../print_/o/inc/o.h"
# include "../print_/u/inc/u.h"
# include "../print_/xX/inc/xx.h"
# include "../print_/scp/inc/scp.h"
# include "../print_/f/inc/ff.h"

int				ft_printf(const char *format, ...);
int				init_param(t_param *param, unsigned int *all_len);
void			is_flag(t_param *param);
void			is_width(t_param *param);
void			is_presition(t_param *param);
void			is_mod(t_param *param);
void			is_type(t_param *param);
int				is_spesific_symb(t_param *param, unsigned int *all_len);
int				compare(char *s1, char *s2);
unsigned	int	ft_strlen(char *str);
void			ft_error_exit();
void			ft_putstr_fd(char *print, t_param *param,
		unsigned int *all_len);
unsigned	int	count_num_min(unsigned long long int num, t_param *param);
unsigned	int	count_num_pl(long long int num);
int				protect_seg(char *str);
short	int		choice_mod(t_param *param);
void			di_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			o_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			u_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			xx_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			ff_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			s_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			c_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			p_func(t_param *param, unsigned int *all_len, t_flags *flag);
void			flag_reset(t_flags *flag);
void			init_flag(t_param *param, t_flags *flag);
void			type_print(t_param *param, unsigned int *all_len);

#endif
