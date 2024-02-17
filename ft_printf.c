/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:58:19 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/16 18:06:26 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkflag(va_list *arg, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*arg, int)));
	if (c == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	if (c == 'u')
		return (ft_putnbr(va_arg(*arg, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(*arg, unsigned int), BASEL, c));
	if (c == 'X')
		return (ft_puthex(va_arg(*arg, unsigned int), BASEU, c));
	if (c == 'p')
		return (ft_puthex(va_arg(*arg, unsigned long), BASEL, c));
	else
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(const	char *frmt, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, frmt);
	len = 0;
	if (write(1, NULL, 0) == -1)
		return (-1);
	while (*frmt)
	{
		if (*frmt != '%')
			len += write(1, frmt, 1);
		else if (*frmt == '%' && *(frmt + 1))
		{
			len += checkflag(&arg, *(frmt + 1));
			frmt++;
		}
		frmt++;
	}
	return (len);
}
