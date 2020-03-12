/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:16:00 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:24:11 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCP_H
# define SCP_H
# include "../../../include/ft_printf.h"

void			default_mod_p(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			default_mod_c(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			default_mod_s(t_param *param, unsigned int *all_len,
		t_flags *flag);
void			init_num_c(t_flags *flag, t_param *param,
		unsigned int *all_len, unsigned char num);
void			init_num_s(t_flags *flag, t_param *param,
		unsigned int *all_len, char *num);
unsigned	int	init_num_16_p(unsigned long long int var,
		t_flags *flag, t_param *param);
unsigned	int	print_num_p(t_param *param, unsigned long long int var);
unsigned	int	is_presition_p(t_param *param);
unsigned	int	is_width_p(t_param *param, t_flags *flag);
unsigned	int	is_sharp_p(t_param *param, t_flags *flag);

#endif
