/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:31:26 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:49:23 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[start] != '\0' && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
