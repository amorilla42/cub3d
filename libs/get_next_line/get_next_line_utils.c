/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:05:56 by jdomingu          #+#    #+#             */
/*   Updated: 2023/07/19 18:12:56 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s1)
{
	int		len;
	int		i;
	char	*res;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	minlen;
	size_t	i;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (0);
	if (slen - start < len)
		minlen = slen - start;
	else
		minlen = len;
	str = (char *) ft_calloc(minlen + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len && i + start < slen)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

void	ft_strjoin_gnl(char **s1, char *s2, size_t s2len)
{
	char	*str;
	size_t	i;
	size_t	s1len;

	if (s2len != 0)
	{
		s1len = ft_strlen(*s1);
		str = (char *) ft_calloc(s1len + s2len + 1, sizeof(char));
		if (!str)
		{
			free(*s1);
			*s1 = 0;
			return ;
		}
		i = -1;
		while (++i < s1len)
			str[i] = (*s1)[i];
		i = -1;
		while (++i < s2len)
			str[s1len + i] = s2[i];
		free(*s1);
		*s1 = str;
	}
}
