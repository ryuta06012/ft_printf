#include "ft_printf.h"

static void	ft_print_unsigned_minus_lx(unsigned int num, t_flag *lay, int *n)
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

static void	ft_print_unsigned_zero_lx(t_flag *lay, int *n)
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

static void	ft_print_unsigned_put_lx(unsigned int num, t_flag *lay, int *n)
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

void	ft_print_unsigned_lx(va_list *ap, t_flag *lay, int *n)
{
	unsigned int	num;

	num = (unsigned int)((unsigned int)va_arg(*ap, \
	 unsigned int) + 1 + UNSIGNED_INT_MAX);
	lay->putlen = nbr_count_hex(num, lay, 16);
	if (num == 0)
		lay->putlen = 1;
	if (lay->accuracy <= -1)
		ft_print_unsigned_minus_lx(num, lay, n);
	else
	{
		if (lay->accuracy == 0 && num == 0)
			ft_print_unsigned_zero_lx(lay, n);
		else
			ft_print_unsigned_put_lx(num, lay, n);
	}
}
