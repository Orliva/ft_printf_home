/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:34:53 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 13:30:52 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_pr
{
	char	*print;
	char	*num;
	char	sign;
	int		i;
	int		dop_mem;
}				t_pr;

typedef	struct	s_flags
{
	int	sharp;
	int	zero;
	int	minus;
	int	plus;
	int	space;
}				t_flags;

typedef	struct	s_param
{
	int				fd;
	va_list			arg;
	char			*dup_format;
	char			*mod;
	char			*flag;
	unsigned	int	len;
	unsigned	int	width;
	unsigned	int	presition;
	char			type;
	char			spesific_symb;
	unsigned	int	n_presit;
	unsigned	int	count;
}				t_param;

#endif
