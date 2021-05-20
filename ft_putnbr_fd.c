#include "ft_printf.h"

void	ft_putnbr_fd(long n, int *num)
{
	int	f;

	f = 1;
	if (n < 0)
		f = -1;
	if (n < 10 && n > -10)
	{
		ft_putchar_fd('0' + n * f, num);
	}
	else
	{
		ft_putnbr_fd(n / 10 * f, num);
		ft_putchar_fd('0' + n % 10 * f, num);
	}
}
