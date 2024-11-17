/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:05:41 by mohben-t          #+#    #+#             */
/*   Updated: 2024/11/14 11:29:45 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_putnbr_base_add(unsigned long nb, char c)
{
	char				*base;
	unsigned long		base_len;
	int					n;

	base_len = 16;
	n = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (nb < base_len)
	{
		n += ft_putchar(base[nb]);
	}
	else
	{
		n += ft_putnbr_base_add(nb / base_len, c);
		n += ft_putnbr_base_add(nb % base_len, c);
	}
	return (n);
}

int	ft_putaddr(unsigned long nb)
{
	int	n;

	n = 0;
	n += ft_putstr("0x");
	n += ft_putnbr_base_add(nb, 'x');
	return (n);
}
