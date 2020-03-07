/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:57:37 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:02:36 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_H
# define U_H
# include "../../../include/ft_printf.h"

void			default_mod_u(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			h_mod_u(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			hh_mod_u(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			l_mod_u(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			ll_mod_u(t_param *param, unsigned int *all_len,
		t_flags *flag);
unsigned	int	init_num_u(unsigned long long int var, t_flags *flag,
		t_param *param);
unsigned	int	is_width_u(t_param *param, t_flags *flag);
unsigned	int	is_presition_u(t_param *param);

#endif
