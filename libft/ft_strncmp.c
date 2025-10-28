/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:01:01 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 16:01:54 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < num - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
