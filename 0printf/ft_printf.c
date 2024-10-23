/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:47:59 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/23 12:04:55 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'p')
		count += ft_putvoid_hex(va_arg(ap, long int));
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else
		count += write(1, &c, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				count += write(1, &(format[i]), 1);
			else
				count += print_flag(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int custom_count;
// 	int original_count;
// 	void *empty_pointer;
// 	void *pointer;
// 	int x;

// 	x = 10;
// 	empty_pointer = NULL;
// 	pointer = &x;
// 	// Prueba con caracteres
// 	custom_count = ft_printf("ft_printf - Prueba de caracter: %c\n", 'A');
// 	original_count = printf("printf    - Prueba de caracter: %c\n", 'A');
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// Prueba con cadenas
// 	custom_count = ft_printf("ft_printf - cadena: %s\n", "Hola, mundo");
// 	original_count = printf("printf    - cadena: %s\n", "Hola, mundo");
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// Prueba con enteros
// 	custom_count = ft_printf("ft_printf - Prueba de entero positivo: %d\n",
// 			12345);
// 	original_count = printf("printf    - Prueba de entero positivo: %d\n",
// 			12345);
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	custom_count = ft_printf("ft_printf - entero negativo: %d\n", -12345);
// 	original_count = printf("printf    - entero negativo: %d\n", -12345);
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// Prueba con unsigned
// 	custom_count = ft_printf("ft_printf - unsigned: %u\n", 4967295);
// 	original_count = printf("printf    - unsigned: %u\n", 4967295);
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// Prueba con hexadecimal (minúsculas)
// 	custom_count = ft_printf("ft_printf - hexadecimal (minúsculas): %x\n", 255);
// 	original_count = printf("printf    - hexadecimal (minúsculas): %x\n", 255);
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// Prueba con hexadecimal (mayúsculas)
// 	custom_count = ft_printf("ft_printf - hexadecimal (mayúsculas): %X\n", 255);
// 	original_count = printf("printf    - hexadecimal (mayúsculas): %X\n", 255);
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// Prueba con el literal %%
// 	custom_count = ft_printf("ft_printf - porcentaje: %%\n");
// 	original_count = printf("printf    - porcentaje: %%\n");
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	custom_count = ft_printf("ft_printf - void %p\n", empty_pointer);
// 	original_count = printf("ft_printf - void %p\n", empty_pointer);
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);

// 	// prueba combi
// 	custom_count = ft_printf("ft_printf - void %p prueba str %s\n", pointer,
// 			"HOLA MUNDOO");
// 	original_count = printf("ft_printf - void %p prueba str %s\n", pointer,
// 			"HOLA MUNDOO");
// 	printf("Caracteres impresos: ft_printf = %d, printf = %d\n\n", custom_count,
// 		original_count);
// 	return (0);
	
// 	//pruebas extra
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);

// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);

// 	ft_printf(" %d ", INT_MIN);

// 	ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

// 	ft_printf(" %i ", INT_MIN);

// 	ft_printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// }
