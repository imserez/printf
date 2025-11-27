/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:11:58 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/30 19:32:51 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_to_hex(unsigned int num, int upper, int bwriten)
{
	int		rest;
	char	*options;
	char	*up_options;

	options = "0123456789abcdef";
	up_options = "0123456789ABCDEF";
	rest = num % 16;
	if (num >= 16)
	{
		num = num / 16;
		bwriten += (num_to_hex(num, upper, 0));
		if (upper != 0)
			bwriten += ft_pt_chr_num(up_options[rest]);
		else
			bwriten += ft_pt_chr_num(options[rest]);
	}
	else
	{
		if (upper != 0)
			bwriten += ft_pt_chr_num(up_options[rest]);
		else
			bwriten += ft_pt_chr_num(options[rest]);
	}
	return (bwriten);
}

int	num_to_hex_ptr(unsigned long num, int upper, int bwriten)
{
	int		rest;
	char	*options;
	char	*up_options;

	options = "0123456789abcdef";
	up_options = "0123456789ABCDEF";
	rest = num % 16;
	if (num >= 16)
	{
		num = num / 16;
		bwriten += (num_to_hex_ptr(num, upper, 0));
		if (upper != 0)
			bwriten += ft_pt_chr_num(up_options[rest]);
		else
			bwriten += ft_pt_chr_num(options[rest]);
	}
	else
	{
		if (upper != 0)
			bwriten += ft_pt_chr_num(up_options[rest]);
		else
			bwriten += ft_pt_chr_num(options[rest]);
	}
	return (bwriten);
}

int	print_pointer(unsigned long ptr)
{
	int	bwriten;

	if (ptr == 0)
		return (ft_pt_str_num("(nil)"));
	bwriten = ft_pt_str_num("0x");
	bwriten += num_to_hex_ptr(ptr, 0, 0);
	return (bwriten);
}
