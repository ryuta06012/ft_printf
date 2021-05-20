#include "ft_printf.h"

void	ft_putnbr_hex_p(unsigned long long n, t_flag *lay, int *num)
{
	unsigned int	r;

	r = 0;
	r = n % 16;
	n = n / 16;
	if (n > 0)
		ft_putnbr_hex_p(n, lay, num);
	if (r >= 0 && r <= 9)
		ft_putchar_fd(r + '0', num);
	else if (r > 9)
	{
		if (lay->specifier == 6 || lay->specifier == 2)
			ft_putchar_fd('a' + r - 10, num);
		if (lay->specifier == 7)
			ft_putchar_fd('A' + r - 10, num);
	}
}
