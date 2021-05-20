#include "ft_printf.h"

static void	ft_putnbr_fd_u(unsigned int n, int *num)
{
	int	f;

	f = 1;
	if (n < 0)
		f = -1;
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd('0' + n * f, num);
	}
	else
	{
		ft_putnbr_fd(n / 10 * f, num);
		ft_putchar_fd('0' + n % 10 * f, num);
	}
}

static void	ft_print_unsigned_minus_u(unsigned int num, t_flag *lay, int *n)
{
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else
		lay->field -= lay->putlen;
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	ft_putnbr_fd_u(num, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_unsigned_zero_u(t_flag *lay, int *n)
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

static void	ft_print_unsigned_put_u(unsigned int num, t_flag *lay, int *n)
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
	ft_putnbr_fd_u(num, n);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

void	ft_print_unsigned_u(va_list *ap, t_flag *lay, int *n)
{
	unsigned int	num;

	num = (unsigned int)((unsigned int)va_arg(*ap, unsigned int) \
	 + 1 + UNSIGNED_INT_MAX);
	lay->putlen = nbr_count_hex(num, lay, 10);
	if (num == 0)
		lay->putlen = 1;
	if (lay->accuracy <= -1)
		ft_print_unsigned_minus_u(num, lay, n);
	else
	{
		if (lay->accuracy == 0 && num == 0)
			ft_print_unsigned_zero_u(lay, n);
		else
			ft_print_unsigned_put_u(num, lay, n);
	}
}
