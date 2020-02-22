#include "../ft_printf.h"

void	free_all(t_param *param)//////Обнулять len, width, presi и тд
{
	free(param->dup_format);
//	free(&param->buff_dest);
	free(param->flag);
	free(param->mod);
//	free(&param->spesific_symb);
}

void    init_param(t_param *param, unsigned int *all_len)
{
        param->dup_format++;///if везде можно убрать если правильно фришить(printf.c)(после%)
	if (*param->dup_format && is_spesific_symb(param, all_len) == 0)
        {
                is_flag(param);
                is_width(param);
                is_presition(param);
                is_mod(param);
                is_type(param);
        }
}
