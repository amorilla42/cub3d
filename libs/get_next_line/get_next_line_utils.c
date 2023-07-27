/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:56 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/09 20:26:03 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_gnl_strdup(char *s1)
{
	int		len;
	int		i;
	char	*res;

	if (!s1)
		return (0);
	len = ft_gnl_strlen(s1);
	res = (char *) ft_gnl_calloc(len + 1, sizeof(char));
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

char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	minlen;
	size_t	i;

	if (!s)
		return (0);
	slen = ft_gnl_strlen(s);
	if (start >= slen)
		return (0);
	if (slen - start < len)
		minlen = slen - start;
	else
		minlen = len;
	str = (char *) ft_gnl_calloc(minlen + 1, sizeof(char));
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

void	ft_gnl_strjoin(char **s1, char *s2, size_t s2len)
{
	char	*str;
	size_t	i;
	size_t	s1len;

	if (s2len != 0)
	{
		s1len = ft_gnl_strlen(*s1);
		str = (char *) ft_gnl_calloc(s1len + s2len + 1, sizeof(char));
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

void	*ft_gnl_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	mult;
	size_t	i;

	mult = count * size;
	if (count != 0 && mult / count != size)
		return (0);
	ptr = (char *) malloc(mult);
	if (!ptr)
		return (0);
	i = 0;
	while (mult--)
		ptr[i++] = 0;
	return (ptr);
}
