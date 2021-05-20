#include "ft_printf.h"

void	ft_putchar_fd(char c, int *n)
{
	*n += write(1, &c, 1);
}
