/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:05:16 by mohben-t          #+#    #+#             */
/*   Updated: 2024/11/14 11:42:58 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr(int nb)//225
{
	long long	number;
	int			n;

	n = 0;
	number = nb;
	if (number < 0)
	{
		n += ft_putchar('-');
		number = -number;
	}
	if (number <= 9)
		n += ft_putchar(number + '0');
	else
	{
		n += ft_putnbr(number / 10);
		n += ft_putnbr(number % 10);
	}
	return (n);
}
