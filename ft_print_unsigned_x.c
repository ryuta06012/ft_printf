#include "ft_printf.h"

static void	ft_print_unsigned_minus_x(unsigned int num, t_flag *lay, int *n)
{
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else
		lay->field -= lay->putlen;
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	ft_putnbr_hex(num, lay, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_unsigned_zero_x(t_flag *lay, int *n)
{
	lay->putlen = 0;
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else
		lay->field -= lay->putlen;
	if (!(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_unsigned_put_x(unsigned int num, t_flag *lay, int *n)
{
	if (lay->accuracy <= lay->putlen)
		lay->accuracy = 0;
	else if (lay->accuracy > lay->putlen)
		lay->accuracy -= lay->putlen;
	lay->acc_num_len = lay->accuracy + lay->putlen;
	if (lay->field <= lay->acc_num_len)
		lay->field = 0;
	else
		lay->field -= lay->acc_num_len;
	if (!(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	ft_put_n_char('0', lay->accuracy, n);
	ft_putnbr_hex(num, lay, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

void	ft_print_unsigned_x(va_list *ap, t_flag *lay, int *n)
{
	unsigned int	num;

	num = (unsigned int)va_arg(*ap, int);
	lay->putlen = nbr_count_hex(num, lay, 16);
	if (num == 0)
		lay->putlen = 1;
	if (lay->accuracy <= -1)
	{
		ft_print_unsigned_minus_x(num, lay, n);
	}
	else
	{
		if (lay->accuracy == 0 && num == 0)
			ft_print_unsigned_zero_x(lay, n);
		else
			ft_print_unsigned_put_x(num, lay, n);
	}
}
