/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:30:41 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/16 18:06:42 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	pwr(int nb, int p)
{
	int	res;

	res = nb;
	if (!p)
		res = 1;
	while (--p > 0)
		res = res * nb;
	return (res);
}

int	ft_putnbr(long n)
{
	long	nb;
	int		len;

	nb = n;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	len = count(nb);
	while (--len >= 0)
		write(1, &B10[(nb / pwr(10, len)) % 10], 1);
	return (count(n));
}
