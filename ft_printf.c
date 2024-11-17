/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:05:46 by mohben-t          #+#    #+#             */
/*   Updated: 2024/11/14 15:26:41 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check(va_list list, const char format)
{
	int	n;

	n = 0;
	if (format == 'd' || format == 'i')
		n = ft_putnbr(va_arg(list, int));
	else if (format == 'u')
		n = ft_putnbr_u(va_arg(list, unsigned int));
	else if (format == 'x')
		n = ft_putnbr_base(va_arg(list, int), format);
	else if (format == 'X')
		n = ft_putnbr_base(va_arg(list, int), format);
	else if (format == 's')
		n = ft_putstr(va_arg(list, char *));
	else if (format == 'p')
		n = ft_putaddr(va_arg(list, unsigned long));
	else if (format == 'c')
		n = ft_putchar((char)va_arg(list, int));
	else if (format == '%')
		n = ft_putchar(format);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		n;

	if (!format || write(1, NULL, 0) == -1)
		return (-1);
	va_start(list, format);
	n = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			n += check(list, *format);
		}
		else
			n += ft_putchar(*format);
		if (*format != '\0')
			format++;
	}
	va_end(list);
	return (n);
}
