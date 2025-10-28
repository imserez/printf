/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 00:42:46 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:56:09 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cp;

	i = 0;
	cp = (unsigned char *) s;
	while (i < n)
	{
		cp[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
