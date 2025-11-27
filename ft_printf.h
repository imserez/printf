/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:58:55 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/30 19:39:47 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *st, ...);
// ft_helpers.c
int	ft_pt_chr_num(const char c);
int	ft_pt_str_num(const char *s);
int	ft_putnbr_num(int n, int bwriten, int negative);
int	ft_putnbr_num_u(unsigned int n, int bwriten);
int	num_to_hex(unsigned int num, int upper, int bwriten);
int	num_to_hex_ptr(unsigned long num, int upper, int bwriten);
int	print_pointer(unsigned long ptr);

#endif
