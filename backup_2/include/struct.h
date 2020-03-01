#ifndef STRUCT_H
#define STRUCT_H

typedef	struct	s_pr
{
	char	*print;
	char	*num;
	char	sign;
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
	char			*dup_format;
	unsigned	int	fF_presi;
	va_list			arg;
	unsigned	int	len;
	char			*flag;
	unsigned	int	width;
	unsigned	int	presition;
	char			*mod;
	char			type;
	char			spesific_symb;
	unsigned	int	s_presit;
	unsigned	int	count;
}				t_param;

#endif
