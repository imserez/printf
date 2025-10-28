/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:37:19 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:57:23 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*c_s;

	c_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (c_s[i] == (unsigned char) c)
			return ((void *)(c_s + i));
		i++;
	}
	return (NULL);
}
