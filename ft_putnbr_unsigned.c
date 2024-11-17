/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:05:21 by mohben-t          #+#    #+#             */
/*   Updated: 2024/11/13 19:05:22 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	unsigned long	number;
	int				n;

	number = nb;
	n = 0;
	if (number <= 9)
		n += ft_putchar(number + '0');
	else
	{
		n += ft_putnbr(number / 10);
		n += ft_putnbr(number % 10);
	}
	return (n);
}
