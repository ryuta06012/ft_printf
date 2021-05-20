#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define UNSIGNED_INT_MAX 4294967295

typedef struct s_flag
{
	int	flag[2];
	int	field;
	int	accuracy;
	int	specifier;
	int	putnum;
	int	putlen;
	int	acc_num_len;
	int	num_sign;
}				t_flag;
size_t	ft_strlen(const char *str);
int		nbr_count_hex(unsigned int num, t_flag *lay, int r);
int		nbr_count_p(unsigned long long num, t_flag *lay, int r);
int		ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		det_char_num(const char **fmt, int id, va_list *ap, t_flag *lay);
int		ft_printf(const char *fmt, ...);
int		ft_det_print(const char **start, const char **fmt, \
va_list *ap, t_flag *lay);
void	ft_print_dec_num(va_list *ap, t_flag *lay, int *n);
void	ft_print_unsigned_u(va_list *ap, t_flag *lay, int *n);
void	ft_print_unsigned_lx(va_list *ap, t_flag *lay, int *n);
void	ft_print_unsigned_x(va_list *ap, t_flag *lay, int *n);
void	ft_print_pointer(va_list *ap, t_flag *lay, int *n);
void	ft_put_n_char(const char s1, int n, int *num);
void	ft_putchar_fd(char c, int *num);
void	ft_putnbr_hex(unsigned int n, t_flag *lay, int *num);
void	ft_putnbr_hex_p(unsigned long long n, t_flag *lay, int *num);
void	ft_putnbr_fd(long n, int *num);

#endif