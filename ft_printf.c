/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:58:32 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/28 20:09:27 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <unistd.h>
// ********************************************
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
// new funcs to get write total.
int	ft_pt_chr_num(const char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_pt_str_num(const char *s)
{
	int	bwriten;

	bwriten = 0;
	while (s[bwriten] != '\0')
		write(1, &s[bwriten++], 1);
	return (bwriten);
}
int	ft_putnbr_num(int n, int bwriten)
{
	if (n == -2147483648)
		return (ft_pt_str_num("-2147483648"));
	else
	{
		if (n < 0)
		{
			bwriten += ft_pt_chr_num('-');
			n = -n;
		}
		if (n >= 10)
			bwriten += ft_putnbr_num(n / 10, bwriten);
		bwriten += ft_pt_chr_num((n % 10) + '0');
		return (bwriten);
	}
}
int ft_putnbr_num_u(unsigned int n, int bwriten)
{
	if (n >= 10)
		bwriten += ft_putnbr_num_u(n / 10, bwriten);
	bwriten += ft_pt_chr_num((n % 10) + '0');
	return (bwriten);
}
int	num_to_hex(unsigned int num, int upper, int bwriten)
{
	int 	rest;
	char	*options = "0123456789abcdef";
	char	*upOptions = "0123456789ABCDEF";

	rest = num % 16;
	if (num > 16)
	{
		num = num / 16;
		bwriten += (num_to_hex(num, upper, bwriten));
		if (upper != 0)
			bwriten += ft_pt_chr_num(upOptions[rest]);
		else
			bwriten += ft_pt_chr_num(options[rest]);

	}
	else
	{
		if (upper != 0)
			bwriten += ft_pt_chr_num(upOptions[rest]);
		else
			bwriten += ft_pt_chr_num(options[rest]);
	}
	return (bwriten);
}

int num_to_hex_ptr(unsigned int num, int upper, int bwriten)
{
    int     rest;
    char    *options = "0123456789abcdef";
    char    *upOptions = "0123456789ABCDEF";

    rest = num % 16;
    if (num > 16)
    {
        num = num / 16;
        bwriten += (num_to_hex(num, upper, bwriten));
        if (upper != 0)
            bwriten += ft_pt_chr_num(upOptions[rest]);
        else
			bwriten += ft_pt_chr_num(options[rest]);
    }
    else
    {
        if (upper != 0)
            bwriten += ft_pt_chr_num(upOptions[rest]);
        else
            bwriten += ft_pt_chr_num(options[rest]);
    }
    return (bwriten);
}


int	print_pointer(unsigned long ptr)
{
	int bwriten;

	bwriten = ft_pt_str_num("0x");
	bwriten += num_to_hex_ptr(ptr, 0, 0);
	return (bwriten);
}

// ********************************************

int	showit(char const *str, size_t pos, va_list ap)
{
	int printed;

	printed = 0;
	if (str[pos] != '\0')
	{
		if (str[pos] == 'c')
		{
			return (ft_pt_chr_num(va_arg(ap, int)));
		}
		else if (str[pos] == 's')
		{
			return (ft_pt_str_num(va_arg(ap, char *)));
		}
		else if (str[pos] == 'p')
		{
			return (print_pointer(va_arg(ap, unsigned long)));
		}
		else if (str[pos] == 'd' || str[pos] == 'i')
		{
			return (ft_putnbr_num(va_arg(ap, int), 0));
		}
		else if (str[pos] == 'u')
		{
			return (ft_putnbr_num_u(va_arg(ap, unsigned int), 0));
		}
		else if (str[pos] == 'X' || str[pos] == 'x')
		{
			return (num_to_hex(va_arg(ap, unsigned int), str[pos] - 'x', 0));
		}
		else if (str[pos] == '%')
		{
			return (ft_pt_str_num("%%"));
		}

	}

	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		b_printed;
	size_t	pos;
	int	res;

	b_printed = 0;
	pos = -1;
	va_start(ap, str);

	while (str[++pos])
	{
		if (str[pos] == '%')
		{
			res = showit(str, pos++ + 1, ap);
			// check if res = -1 for possible errors.
			b_printed += res;
		}
		else
			b_printed += ft_pt_chr_num(str[pos]);
	}
	va_end(ap);
	return (b_printed);
}

int main(void)
{
	int test = 12;

	// int printed = ft_printf("5+-%c-\n", 'k');
	// int printed = ft_printf("5+-%s-\n", "casa");
	// int printed = ft_printf(5+-%i-\n", 12312312);
	// 	int printed = ft_printf("5+-%u-\n", 12312312);
	// 	int printed = ft_printf("5+-%x-\n", 445); // 1bd
	int printed = ft_printf("5+-%p-\n", test); // 1bd

	ft_printf("%i", printed);

}


