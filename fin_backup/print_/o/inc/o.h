/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:51:41 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:57:26 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_H
# define O_H
# include "../../../include/ft_printf.h"

void			default_mod_o(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			h_mod_o(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			hh_mod_o(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			l_mod_o(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			ll_mod_o(t_param *param, unsigned int *all_len,
		t_flags *flag);
unsigned	int	init_num_8(unsigned long long int var, t_flags *flag,
		t_param *param);
unsigned	int	is_presition_o(t_param *param);
unsigned	int	is_width_o(t_param *param, t_flags *flag);
unsigned	int	is_sharp_o(t_param *param, t_flags *flag);

#endif
