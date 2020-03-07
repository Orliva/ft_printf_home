/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fF.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:40:02 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:22:05 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FF_H
# define FF_H
# include "../../../include/ft_printf.h"

unsigned	int	count_num_f(long double var);
unsigned	int	val(t_param *param, t_flags *flag, long double var);
void			default_mod_f(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			l_mod_f(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			l_up_mod_f(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			init_num_f(t_pr *pr, t_param *param, t_flags *flag,
		long double num);
void			is_sign_space_f(t_pr *pr, t_param *param, t_flags *flag);
void			is_width_f(t_pr *pr, t_param *param, t_flags *flag,
		unsigned int val_);
void			right_pos_f(t_pr *pr, t_param *param, t_flags *flag,
		unsigned int val_);
void			rouding(t_pr *pr, t_param *param, long double var);
long	double	ft_pow_lld(long double num, unsigned int count);

#endif
