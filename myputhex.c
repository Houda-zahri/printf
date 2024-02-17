/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:30:29 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/15 23:23:40 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, char *base, char c)
{
	int	len ;

	len = 0;
	(c == 'p') && (len += write (1, "0x", 2), c = 0);
	(nb > 15) && (len += ft_puthex(nb / 16, base, c));
	len += write (1, &base[nb % 16], 1);
	return (len);
}
