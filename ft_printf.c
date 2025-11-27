/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:58:32 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/30 19:41:01 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	showit(char const *str, size_t pos, va_list ap)
{
	if (str[pos] != '\0')
	{
		if (str[pos] == 'c')
			return (ft_pt_chr_num(va_arg(ap, int)));
		else if (str[pos] == 's')
			return (ft_pt_str_num(va_arg(ap, char *)));
		else if (str[pos] == 'p')
			return (print_pointer(va_arg(ap, unsigned long)));
		else if (str[pos] == 'd' || str[pos] == 'i')
			return (ft_putnbr_num(va_arg(ap, int), 0, 0));
		else if (str[pos] == 'u')
			return (ft_putnbr_num_u(va_arg(ap, unsigned int), 0));
		else if (str[pos] == 'X' || str[pos] == 'x')
			return (num_to_hex(va_arg(ap, unsigned int), str[pos] - 'x', 0));
		else if (str[pos] == '%')
			return (ft_pt_chr_num('%'));
		else
			return (-1);
	}
	return (-2);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		b_printed;
	size_t	pos;
	int		res;

	b_printed = 0;
	pos = -1;
	va_start(ap, str);
	if (str == NULL || !str)
		return (-1);
	while (str[++pos] && b_printed != -1)
	{
		if (str[pos] == '%')
		{
			res = showit(str, pos++ + 1, ap);
			b_printed += res;
			if (res == -1)
				b_printed = -1;
		}
		else
			b_printed += ft_pt_chr_num(str[pos]);
	}
	va_end(ap);
	return (b_printed);
}
