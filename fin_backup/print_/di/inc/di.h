/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:50:14 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:51:28 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DI_H
# define DI_H
# include "../../../include/ft_printf.h"

void			default_mod_di(t_param *param,
		unsigned int *all_len, t_flags *flag);
void			h_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void			hh_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void			l_mod_di(t_param *param, unsigned int *all_len, t_flags *flag);
void			ll_mod_di(t_param *param,
		unsigned int *all_len, t_flags *flag);
unsigned	int	init_num_di(t_pr *pr,
		long long int var, t_flags *flag, t_param *param);
unsigned	int	is_presition_di(t_param *param);
unsigned	int	is_width_di(t_param *param, t_flags *flag);
unsigned	int	is_sign_space_di(t_pr *pr, t_param *param, t_flags *flag);
unsigned	int	print_num_di(t_param *param, long long int var);

#endif
