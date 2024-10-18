#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
//#include "libft.h"


int	print_char(int c)
{
	return (write(1, &c, 1));
}

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int	print_str(char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
		write(1, &s[count++], 1);
	return count;
}

int	ft_putnbr_base(long nb, char *base)
{
	char	c;
	int		min_int_flag;
	int	count;
	
	count = 0;
	min_int_flag = 0;
	if (nb == -2147483648)
	{
		min_int_flag = 1;
		nb++;
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= ft_strlen(base))
		count += ft_putnbr_base(nb / ft_strlen(base), base);
	if (min_int_flag)
		c = base[(nb % ft_strlen(base)) - 1];
	else
		c = base[nb % ft_strlen(base)];
	count += write(1, &c, 1);
	return (count);
}

int	print_flag(const char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(ap, int));
	else if (c == 's')
		count += print_str(va_arg(ap, char *));
	else if ((c == 'd') || (c == 'i'))
		count += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		{
		count += ft_putnbr_base(va_arg(ap, int), "0123456789");			
		}
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else
		count += write(1, &c, 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int count;
	int	i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if(format[i] == '%')
		{
			if(format[++i] == '%')
				count += write(1, &(format[i]), 1);
			else
				count += print_flag(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return(count);
}


int main(void)
{
    int custom_count;
    int original_count;

    // Prueba con caracteres
    custom_count = ft_printf("ft_printf - Prueba de caracter: %c\n", 'A');
    original_count = printf("printf    - Prueba de caracter: %c\n", 'A');
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    // Prueba con cadenas
    custom_count = ft_printf("ft_printf - Prueba de cadena: %s\n", "Hola, mundo");
    original_count = printf("printf    - Prueba de cadena: %s\n", "Hola, mundo");
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    // Prueba con enteros
    custom_count = ft_printf("ft_printf - Prueba de entero positivo: %d\n", 12345);
    original_count = printf("printf    - Prueba de entero positivo: %d\n", 12345);
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    custom_count = ft_printf("ft_printf - Prueba de entero negativo: %d\n", -12345);
    original_count = printf("printf    - Prueba de entero negativo: %d\n", -12345);
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    // Prueba con unsigned
    custom_count = ft_printf("ft_printf - Prueba de unsigned: %u\n", 4967295);
    original_count = printf("printf    - Prueba de unsigned: %u\n", 4967295);
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    // Prueba con hexadecimal (minúsculas)
    custom_count = ft_printf("ft_printf - Prueba de hexadecimal (minúsculas): %x\n", 255);
    original_count = printf("printf    - Prueba de hexadecimal (minúsculas): %x\n", 255);
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    // Prueba con hexadecimal (mayúsculas)
    custom_count = ft_printf("ft_printf - Prueba de hexadecimal (mayúsculas): %X\n", 255);
    original_count = printf("printf    - Prueba de hexadecimal (mayúsculas): %X\n", 255);
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    // Prueba con el literal %%
    custom_count = ft_printf("ft_printf - Prueba con porcentaje: %%\n");
    original_count = printf("printf    - Prueba con porcentaje: %%\n");
    printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count, original_count);

    return 0;
}