#include "ft_printf.h"

int	nbr_count(long num, t_flag *lay, int r)
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

static void	ft_print_dec_num_minus(int num, t_flag *lay, int *n)
{
	if (lay->num_sign == 1)
		lay->putlen += 1;
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else
		lay->field -= lay->putlen;
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->num_sign == 1)
		*n += write (1, "-", 1);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	ft_putnbr_fd(num, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_signed_zero(t_flag *lay, int *n)
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

static void	ft_print_signed(int num, t_flag *lay, int *n)
{
	if (lay->accuracy <= lay->putlen)
		lay->accuracy = 0;
	else if (lay->accuracy > lay->putlen)
		lay->accuracy -= lay->putlen;
	lay->acc_num_len = lay->accuracy + lay->putlen;
	if (lay->num_sign == 1)
		lay->acc_num_len += 1;
	if (lay->field <= lay->acc_num_len)
		lay->field = 0;
	else
		lay->field -= lay->acc_num_len;
	if (!(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->num_sign == 1)
		*n += write (1, "-", 1);
	ft_put_n_char('0', lay->accuracy, n);
	ft_putnbr_fd(num, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

void	ft_print_dec_num(va_list *ap, t_flag *lay, int *n)
{
	int	num;

	num = va_arg(*ap, int);
	lay->putlen = nbr_count(num, lay, 10);
	if (num == 0)
		lay->putlen = 1;
	if (lay->accuracy <= -1)
	{
		ft_print_dec_num_minus(num, lay, n);
	}
	else
	{
		if (lay->accuracy == 0 && num == 0)
			ft_print_signed_zero(lay, n);
		else
			ft_print_signed(num, lay, n);
	}
}
