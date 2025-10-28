/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:32:52 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:50:21 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	last = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			last = i;
		i++;
	}
	if (last >= 0)
		return ((char *) &s[last]);
	if ((unsigned char)c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
