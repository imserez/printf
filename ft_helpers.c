/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:03:40 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/30 19:37:30 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pt_chr_num(const char c)
{
	return (write(1, &c, 1));
}

int	ft_pt_str_num(const char *s)
{
	int	bwriten;
	int	i;
	int	tmp_write;

	i = 0;
	bwriten = 0;
	if (!s)
		return (ft_pt_str_num("(null)"));
	while (s[i] != '\0')
	{
		tmp_write = write(1, &s[i++], 1);
		if (tmp_write == -1)
			return (-1);
		bwriten += tmp_write;
	}
	return (bwriten);
}

int	ft_putnbr_num(int n, int bwriten, int negative)
{
	if (!n)
		return (ft_pt_chr_num('0'));
	if (n == -2147483648)
		return (ft_pt_str_num("-2147483648"));
	else
	{
		if (n < 0 && negative == 0)
		{
			bwriten += ft_pt_chr_num('-');
			negative = 1;
			n = n * -1;
		}
		if (n >= 10)
			bwriten += ft_putnbr_num(n / 10, 0, negative);
		bwriten += ft_pt_chr_num((n % 10) + '0');
		return (bwriten);
	}
}

int	ft_putnbr_num_u(unsigned int n, int bwriten)
{
	int	tmp_write;

	if (!n)
		return (ft_pt_chr_num('0'));
	if (n >= 10)
	{
		tmp_write = ft_putnbr_num_u(n / 10, 0);
		if (tmp_write == -1)
			return (-1);
		bwriten += tmp_write;
	}
	tmp_write = ft_pt_chr_num((n % 10) + '0');
	if (tmp_write == -1)
		return (-1);
	bwriten += tmp_write;
	return (bwriten);
}
