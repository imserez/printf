/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:16:36 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/28 16:46:12 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*alocation;
	size_t	total;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (num > SIZE_MAX / size)
		return (NULL);
	total = num * size;
	alocation = malloc(size * num);
	if (alocation == NULL)
		return (NULL);
	ft_bzero(alocation, num * size);
	return (alocation);
}
