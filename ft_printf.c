#include "ft_printf.h"

void	ft_init_flag(t_flag *s)
{
	s->flag[0] = 0;
	s->flag[1] = 0;
	s->field = -1;
	s->accuracy = -1;
	s->specifier = -1;
	s->putnum = 0;
	s->putlen = 0;
	s->acc_num_len = 0;
	s->num_sign = 0;
}

void	ft_dis_per(const char **start, const char **fmt, int *n, \
va_list *ap)
{
	t_flag	lay;
	int		num;

	num = -1;
	ft_init_flag(&lay);
	(*fmt)++;
	while (ft_strchr("0-", **fmt) >= 0)
	{
		num = ft_strchr("0-", **fmt);
		lay.flag[num] = 1;
		(*fmt)++;
	}
	lay.field = det_char_num(fmt, 0, ap, &lay);
	if (**fmt == '.')
	{
		(*fmt)++;
		lay.accuracy = det_char_num(fmt, 1, ap, &lay);
	}
	lay.specifier = ft_strchr("cspdiuxX%", **fmt);
	num = ft_det_print(start, fmt, ap, &lay);
	if ((n == 0) || (num > 0))
		*n += num;
	else
		*n += 0;
}

void	ft_create_str(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write (1, *start, *fmt - *start);
	*n += *fmt - *start;
}

int	ft_printf(const char *fmt, ...)
{
	const char	*start;
	va_list		ap;
	int			n;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			ft_create_str(&start, &fmt, &n);
		else
			ft_dis_per(&start, &fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}
