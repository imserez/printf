/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:11:45 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/24 20:26:44 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(char const *s, char c)
{
	int	i;
	int	founds;
	int	valid;

	valid = 0;
	founds = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && valid)
		{
			founds++;
			valid = 0;
		}
		else if (s[i] != c)
			valid = 1;
		i++;
	}
	if (valid)
		founds++;
	return (founds);
}

static char	**clean_all(char **splits, int maxIndex)
{
	int	i;

	i = 0;
	while (i < maxIndex)
	{
		free(splits[i]);
		splits[i] = NULL;
		i++;
	}
	free(splits);
	return (NULL);
}

static char	**last_secure_check(char *gen, char **splits, int founds, int valid)
{
	if (valid != -1)
	{
		if (!gen)
			return (clean_all(splits, founds));
		splits[founds] = gen;
	}
	return (splits);
}

static char	**perform_substr(char const *s, char c, char **splits, int *founds)
{
	int		i;
	int		valid;
	char	*gen;

	*founds = 0;
	valid = -1;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c && valid != -1)
		{
			gen = ft_substr(s, valid, i - valid);
			if (!gen)
				return (clean_all(splits, *founds));
			splits[(*founds)++] = gen;
			valid = -1;
		}
		else if (valid == -1 && s[i] != c)
			valid = i;
	}
	if (valid != -1)
		gen = ft_substr(s, valid, i - valid);
	return (last_secure_check(gen, splits, *founds, valid));
}

char	**ft_split(char const *s, char c)
{
	int		substrings;
	char	**splits;
	int		founds;

	if (!s)
		return (NULL);
	substrings = count_subs(s, c);
	splits = (char **)malloc(sizeof(char *) * (substrings + 1));
	if (!splits)
		return (NULL);
	splits[substrings] = NULL;
	splits = (perform_substr(s, c, splits, &founds));
	return (splits);
}
