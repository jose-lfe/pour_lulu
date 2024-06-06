/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:21:17 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:55 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_exception(int *count)
{
	write(1, "-2147483648", 11);
	(*count) = (*count) + 11;
}

void	ft_putnbr(int n, int *count)
{
	int	digit;

	digit = 0;
	if (n == -2147483648)
		ft_exception(count);
	else if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
		ft_putnbr(n, count);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10, count);
			ft_putnbr(n % 10, count);
		}
		else
		{
			digit = n + 48;
			ft_putchar(digit, count);
		}
	}
}
