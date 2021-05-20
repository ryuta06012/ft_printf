#include "ft_printf.h"

static void	ft_print_pointer_minus(unsigned long long num, t_flag *lay, int *n)
{
	if (lay->field <= (lay->putlen + 2))
		lay->field = 0;
	else
		lay->field -= (lay->putlen + 2);
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	*n += write(1, "0x", 2);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	ft_putnbr_hex_p(num, lay, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_pointer_zero(t_flag *lay, int *n)
{
	lay->putlen = 2;
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else
		lay->field -= lay->putlen;
	if (!(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	*n += write(1, "0x", 2);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_pointer_put(unsigned long long num, \
t_flag *lay, int *n)
{
	if (lay->accuracy <= lay->putlen)
		lay->accuracy = 0;
	else if (lay->accuracy > lay->putlen)
		lay->accuracy -= lay->putlen;
	lay->acc_num_len = lay->accuracy + lay->putlen + 2;
	if (lay->field <= lay->acc_num_len)
		lay->field = 0;
	else
		lay->field -= lay->acc_num_len;
	if (!(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	*n += write(1, "0x", 2);
	ft_put_n_char('0', lay->accuracy, n);
	ft_putnbr_hex_p(num, lay, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

void	ft_print_pointer(va_list *ap, t_flag *lay, int *n)
{
	unsigned long long	num;

	num = (unsigned long long)va_arg(*ap, void *);
	lay->putlen = nbr_count_p(num, lay, 16);
	if (num == 0)
		lay->putlen = 1;
	if (lay->accuracy <= -1)
		ft_print_pointer_minus(num, lay, n);
	else
	{
		if (lay->accuracy == 0 && num == 0)
			ft_print_pointer_zero(lay, n);
		else
			ft_print_pointer_put(num, lay, n);
	}
}
