#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int ret = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ret += ft_putchar(*str);
		str++;
	}
	return (ret);
}

int ft_putnum(long n)
{
	int ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
		ret += ft_putnum(n / 10);
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}

int ft_puthex(unsigned int hex)
{
	int ret = 0;
	char *base = "0123456789abcdef";
	if (hex >= 16)
		ret += ft_puthex(hex /16);
	ret += ft_putchar(base[hex % 16]);
	return (ret);
}

int ft_printf(const char *format, ... )
{
	int ret = 0;
	va_list ap;
	va_start(ap, format);
	while(*format)
	{
		if(*format =='%')
		{
			format++;
			if(*format == 's')
				ret += ft_putstr(va_arg(ap, char *));
			else if(*format == 'd')
				ret += ft_putnum(va_arg(ap, int));
			else if(*format == 'x')
				ret += ft_puthex(va_arg(ap, unsigned int));
			format++;
		}
		else
		{
			ret += ft_putchar(*format);
			format++;	
		}
	}
	va_end(ap);
	return(ret);
}

/*#include <stdio.h>
int main(void)
{
	char *fr = "def";
	int n = 42;
	int h = 456;
	int a = printf("abc_%s_%d_%x\n", fr, n, h);
	int b = ft_printf("abc_%s_%d_%x\n", fr, n, h);
	printf("%d_%d", a, b);

}*/