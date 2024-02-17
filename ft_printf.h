/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 01:04:36 by hzahri            #+#    #+#             */
/*   Updated: 2023/12/16 18:09:19 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define BASEL "0123456789abcdef"
# define BASEU "0123456789ABCDEF"
# define B10 "0123456789"

int	ft_printf(const	char *frmt, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned long n, char *base, char c);
int	ft_putnbr(long n);
int	ft_putstr(char *str);

#endif