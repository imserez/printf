/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:50:34 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:52:31 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	size_t		i;
	char		*new;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}
