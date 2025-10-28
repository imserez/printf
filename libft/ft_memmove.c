/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 03:50:05 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:56:29 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*c_dest;
	const unsigned char	*c_src;
	size_t				i;

	c_dest = (unsigned char *) dest;
	c_src = (const unsigned char *) src;
	if (c_dest > c_src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			c_dest[i] = c_src[i];
		}
	}
	else if (c_dest < c_src)
	{
		i = 0;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}
