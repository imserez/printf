/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:05:03 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:51:43 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new;

	len = 0;
	while (s[len] != '\0')
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		new[len] = (*f)(len, s[len]);
		len++;
	}
	new[len] = '\0';
	return (new);
}
