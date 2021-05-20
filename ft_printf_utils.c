#include "ft_printf.h"

static int	ft_print_non_specifier(const char **start, const char **fmt, \
t_flag *lay)
{
	if (!**fmt)
		return (-1);
	lay->putlen = *fmt - *start;
	write (1, *start, lay->putlen);
	return (lay->putlen);
}

static void	ft_print_string(va_list *ap, t_flag *lay, int *n)
{
	char	*str;

	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		str = "(null)";
		lay->putlen = 6;
	}
	else
		lay->putlen = (int)ft_strlen(str);
	if (lay->accuracy < 0)
		lay->accuracy = INT_MAX;
	else if (lay->accuracy <= lay->putlen)
		lay->putlen = lay->accuracy;
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else if (lay->field > lay->putlen)
		lay->field -= lay->putlen;
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	*n += write(1, str, lay->putlen);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_char(va_list *ap, t_flag *lay, int *n)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*ap, int);
	lay->putlen = 1;
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else if (lay->field > lay->putlen)
		lay->field -= lay->putlen;
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	*n += write(1, &c, 1);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

static void	ft_print_per(t_flag *lay, int *n)
{
	lay->putlen = 1;
	if (lay->field <= lay->putlen)
		lay->field = 0;
	else if (lay->field > lay->putlen)
		lay->field -= lay->putlen;
	if (!(lay->flag[0]) && !(lay->flag[1]))
		ft_put_n_char(' ', lay->field, n);
	if (lay->flag[0] && !(lay->flag[1]))
		ft_put_n_char('0', lay->field, n);
	*n += write(1, "%%", 1);
	if (lay->flag[1])
		ft_put_n_char(' ', lay->field, n);
}

int	ft_det_print(const char **start, const char **fmt, va_list *ap, t_flag *lay)
{
	int	n;

	n = 0;
	if (lay->specifier == -1)
		return (ft_print_non_specifier(start, fmt, lay));
	(*fmt)++;
	if ((lay)->specifier == 0)
		ft_print_char(ap, lay, &n);
	else if (lay->specifier == 1)
		ft_print_string(ap, lay, &n);
	else if (lay->specifier == 2)
		ft_print_pointer(ap, lay, &n);
	else if (lay->specifier == 3 || lay->specifier == 4)
		ft_print_dec_num(ap, lay, &n);
	else if (lay->specifier == 5)
		ft_print_unsigned_u(ap, lay, &n);
	else if (lay->specifier == 6)
		ft_print_unsigned_x(ap, lay, &n);
	else if (lay->specifier == 7)
		ft_print_unsigned_lx(ap, lay, &n);
	else
		ft_print_per(lay, &n);
	return (n);
}
