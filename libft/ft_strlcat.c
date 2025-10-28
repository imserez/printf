/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:32:20 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:52:24 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
