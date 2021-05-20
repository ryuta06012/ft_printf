#include "ft_printf.h"

void	ft_put_n_char(const char s1, int n, int *num)
{
	while (n != 0)
	{
		*num += write(1, &s1, 1);
		n--;
	}
}
