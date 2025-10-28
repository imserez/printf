/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:52:00 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:58:32 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_numlen(int n)
{
	int	tmpnum;
	int	numlen;

	if (n == 0)
		return (1);
	numlen = 0;
	tmpnum = n;
	while (tmpnum > 0)
	{
		tmpnum /= 10;
		numlen++;
	}
	return (numlen);
}

static void	fill_num(char *res, int numlen, int nega, int n)
{
	while (numlen > 0)
	{
		res[numlen + nega - 1] = n % 10 + '0';
		numlen--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		nega;
	int		numlen;
	char	*res;

	nega = n < 0;
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (nega)
		n *= -1;
	numlen = get_numlen(n);
	res = (char *)malloc(sizeof(char) * (numlen + nega + 1));
	if (!res)
		return (NULL);
	res[numlen + nega] = '\0';
	if (nega)
		res[0] = '-';
	fill_num(res, numlen, nega, n);
	return (res);
}
