#include "ft_printf.h"

int	nbr_count_hex(unsigned int num, t_flag *lay, int r)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		num *= -1;
		lay->num_sign = 1;
	}
	while (num > 0)
	{
		i++;
		num = num / r;
	}
	return (i);
}
