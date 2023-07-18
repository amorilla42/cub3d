/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:02:36 by jdomingu          #+#    #+#             */
/*   Updated: 2022/05/05 20:52:32 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_wordlength(char const *s, char c, int i)
{
	int	j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	return (j - i);
}

static char	*ft_newword(char const *s, char c, int idx)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = ft_wordlength(s, c, idx);
	word = (char *) malloc ((j + 1) * sizeof(char));
	if (!word)
	{
		free(word);
		return (0);
	}
	while (s[idx] && i < j)
	{
		word[i] = s[idx];
		i++;
		idx++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	j = 0;
	str = (char **) ft_calloc((ft_nwords(s, c) + 1), sizeof(char *));
	if (!str)
		return (0);
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{
			str[i] = ft_newword(s, c, j);
			i++;
		}
		while (s[j] && s[j] != c)
			j++;
	}
	return (str);
}
