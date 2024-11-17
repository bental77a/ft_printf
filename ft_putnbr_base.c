/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:05:26 by mohben-t          #+#    #+#             */
/*   Updated: 2024/11/15 00:16:56 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_base(unsigned int nb, char c)
{
	char			*base;
	unsigned int	base_len;
	int				n;

	n = 0;
	base_len = 16;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb < base_len)
	{
		n += ft_putchar(base[nb]);
	}
	else
	{
		n += ft_putnbr_base(nb / base_len, c);
		n += ft_putnbr_base(nb % base_len, c);
	}
	return (n);
}
