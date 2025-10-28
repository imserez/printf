/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 01:09:05 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/09 18:52:12 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;
	size_t				i;

	i = 0;
	char_dest = (unsigned char *) dest;
	char_src = (const unsigned char *) src;
	if (!char_dest && !char_src)
		return (NULL);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
