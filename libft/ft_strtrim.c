/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:10:04 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 15:48:35 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*copy_str(char const *s1, size_t st, size_t end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (end - st + 2));
	if (str == NULL)
		return (NULL);
	while (s1[st] != '\0' && st <= end)
		str[i++] = s1[st++];
	str[i] = '\0';
	return (str);
}

static char	*empty_str(void)
{
	char	*empty;

	empty = (char *)malloc(sizeof(char) * 1);
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && start <= end)
	{
		if (is_inset(s1[start], set))
			start++;
		if (is_inset(s1[end], set))
			end--;
		i++;
	}
	if (start > end)
		return (empty_str());
	return (copy_str(s1, start, end));
}
