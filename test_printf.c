#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_info {
	char type;
	int width;
	int prec;
	int sign;
	int base;
}				t_info;

void info_init(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->prec = -1;
	info->sign = 1;
	info->base = 10;
}

char *ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return str + i;
		i++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return i;
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_putstr(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

char *ft_baseset(char type)
{
	if (type == 'd')
		return "0123456789";
	else
		return "0123456789abcdef";
}

int ft_nbrlen(unsigned int num, t_info *info)
{
	int ret;

	ret = 0;
	if (num == 0 && info->prec < 0)
		return (1);
	while (num)
	{
		num /= info->base;
		ret++;
	}
	return (ret);
}

int put_str_width(int width, int len)
{
	int ret;

	ret = 0;
	while (width > len)
	{
		write(1, " ", 1);
		len++;
		ret++;
	}
	return (ret);
}

int print_nbr(unsigned int nbr, t_info *info)
{
	char *buf;
	int ret;

	if (info->type == 'x')
		info->base = 16;
	if (info->type =='d' && (int)nbr < 0)
	{
		info->sign = -1;
		nbr = -nbr;
	}
	if (nbr == 0 && info->prec < 0)
		info->prec = 1;
	if (info->prec < ft_nbrlen(nbr, info))
		info->prec = ft_nbrlen(nbr, info);
	if (info->sign < 0)
		info->prec++;
	if (!(buf = malloc(sizeof(char) * info->prec + 1)))
		return 0;
	buf[info->prec] = 0;
	ret = info->prec;
	while (nbr)
	{
		buf[--ret] = ft_baseset(info->type)[nbr % info->base];
		nbr /= info->base;
	}
	while (ret > 0)
		buf[--ret] = '0';
	if (info->sign < 0)
		buf[0] = '-';
	ret = put_str_width(info->width, ft_strlen(buf));
	ret += ft_putstr(buf);
	free(buf);
	return ret;
}

int print_str(char *str, t_info *info)
{
	int ret;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	ret = put_str_width(info->width, info->prec);
	int i = 0;
	while (i < info->prec)
	{
		write(1, str + i, 1);
		i++;
	}
	ret += i;
	return ret;
}

int print_val(va_list arg, t_info *info)
{
	if (info->type == 'd')
		return print_nbr(va_arg(arg, int), info);
	else if (info->type == 's')
		return print_str(va_arg(arg, char*), info);
	else
		return print_nbr(va_arg(arg, unsigned int), info);
}

int ft_format(char *format, va_list arg, t_info* info)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			info_init(info);
			while (format[++i] && !ft_strchr("sdx", format[i]))
			{
				if (format[i] == '.')
					info->prec = 0;
				else if (ft_strchr("0123456789", format[i]))
				{
					if (info->prec == -1)
						info->width = info->width * 10 + format[i] - '0';
					else
						info->prec = info->prec * 10 + format[i] - '0';
				}
			}
			info->type = format[i] ? format[i++] : 0;
			ret += print_val(arg, info);
		}
	}
	return ret;
}

int ft_printf(const char *str, ...)
{
	va_list arg;
	t_info *info;
	int i, ret;

	va_start(arg, str);
	if (!(info = malloc(sizeof(t_info))))
		return -1;
	i = 0;
	ret = ft_format((char*)str, arg, info);
	free(info);
	va_end(arg);
	return (ret);
}
