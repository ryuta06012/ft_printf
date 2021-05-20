#include "ft_printf.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	det_char_num(const char **fmt, int id, va_list *ap, t_flag *lay)
{
	int	num;

	num = -1;
	if (**fmt == '*')
	{
		num = va_arg(*ap, int);
		if (id == 0 && (num < 0))
		{
			num *= -1;
			lay->flag[1] = 1;
		}
		else if (num < 0)
			num = -1;
		(*fmt)++;
	}
	else if (id == 1 || ft_isdigit(**fmt))
	{
		num = 0;
		while (ft_isdigit(**fmt))
			num = num * 10 + (*((*fmt)++) - '0');
	}
	return (num);
}
