/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:02:45 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:15:51 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XX_H
# define XX_H
# include "../../../include/ft_printf.h"

void			default_mod_xx(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			h_mod_xx(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			hh_mod_xx(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			l_mod_xx(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			ll_mod_xx(t_param *param, unsigned int *all_len,
		t_flags *flag);
unsigned	int	init_num_16_xx(unsigned long long int var, t_flags *flag,
		t_param *param);
unsigned	int	print_num_xx(t_param *param, unsigned long long int var);
unsigned	int	is_presition_xx(t_param *param);
unsigned	int	is_width_xx(t_param *param, t_flags *flag);
unsigned	int	is_sharp_xx(t_param *param, t_flags *flag);

#endif
