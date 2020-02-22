#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	argptr;
	/////////Функция которая смотри format на наличие специальных знаков
	/////////Создать указатель на функцию, и передавать агрументы
	
	i = 0;
	va_start(argptr, format);
	while (format[i])
	{
		write(1, &format[i], 1);
		write(1, "\n", 1);
		i++;
	}
	va_end(argptr);
	return (0);
}
