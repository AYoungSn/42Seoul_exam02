#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_info{
	char type;
	int width;
	int prec;
	int sign;
	int base;
	char zero;
} t_info;

void info_init(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->prec = -1;
	info->sign = 1;
	info->base = 10;
	info->zero = 0;
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

char *ft_strchr(char *str, char ch)
{
	while (*str && *str != ch)
		str++;
	if (*str == ch)
		return str;
	return 0;
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void check_info(t_info *info, char flag)
{
	if (flag == '.')
		info->prec = 0;
	else if (flag == '0' && info->width == 0 && info->prec == -1)
		info->zero = '0';
	else if (ft_strchr("0123456789", flag))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + flag - '0';
		else
			info->prec = info->prec * 10 + flag - '0';
	}
}

int ft_nbrlen(unsigned int num, t_info *info)
{
	int i;

	i = 0;
	if (num == 0 && info->prec != 0)
		return (1);
	while (num)
	{
		num /= info->base;
		i++;
	}
	return (i);
}

int	put_str_width(int width, int len)
{
	int ret;

	ret = 0;
	while (len < width)
	{
		write(1, " ", 1);
		len++;
		ret++;
	}
	return (ret);
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

char *ft_baseset(char ch)
{
	if (ch == 'x')
		return "0123456789abcdef";
	else
		return "0123456789";
}

int	print_nbr(unsigned int num, t_info *info)
{
	char *buf;
	int ret;

	if (info->type == 'x')
		info->base = 16;
	if (info->type == 'd' && (int)num < 0)
	{
		info->sign = -1;
		num = -num;
	}
	if (num == 0 && info->prec < 0)
		info->prec = 1;
	if (info->prec < ft_nbrlen(num, info))
		info->prec = ft_nbrlen(num, info);
	if (info->sign < 0)
		info->prec++;
	if (!(buf = malloc(sizeof(char) * info->prec + 1)))
		return (0);
	buf[info->prec] = 0;
	ret = info->prec;
	while (num)
	{
		buf[--ret] = ft_baseset(info->type)[num % info->base];
		num /= info->base;
	}
	while (ret > 0)
		buf[--ret] = '0';
	if (info->sign < 0)
		buf[0] = '-';
	ret = put_str_width(info->width, ft_strlen(buf));
	ret += ft_putstr(buf);
	free(buf);
	return (ret);
}

int print_str(char *str, t_info* info)
{
	int ret;
	int i;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	ret = put_str_width(info->width, info->prec);
	i = 0;
	while (i < info->prec)
	{
		write(1, str + i, 1);
		i++;
	}
	ret += i;
	return (ret);
}

int print_val(va_list arg, t_info *info)
{
	int ret;

	ret = 0;
	if (info->type == 'd')
		ret = print_nbr(va_arg(arg, int), info);
	else if (info->type == 's')
		ret = print_str(va_arg(arg, char*), info);
	else if (info->type == 'x')
		ret = print_nbr(va_arg(arg, unsigned int), info);
	return ret;
}

int ft_format(char *format, va_list arg, t_info *info)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			info_init(info);
			while (format[++i] && !ft_strchr("sdx", format[i]))
				check_info(info, format[i]);
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
	int i;
	int ret;

	va_start(arg, str);
	if (!(info = malloc(sizeof(t_info))))
		return -1;
	i = 0;
	ret = ft_format((char*)str, arg, info);
	/*
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
			ret += ft_putchar(str[i++]);
		if (str[i] == '%')
		{
			info_init(info);
			while (str[++i] && !ft_strchr("sdx", str[i]))
				check_info(info, str[i]);
			info->type = str[i] ? str[i++] : 0;
			ft_putstr("info->type: ");
			ft_putstr(&info->type);
			ft_putstr("\n");
			ret += print_val(arg, info);
		}
	}
	*/
	free(info);
	va_end(arg);
	return (ret);
}
