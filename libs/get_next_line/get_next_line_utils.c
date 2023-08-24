/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:35:38 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/11 18:42:00 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t num, size_t size)
{
	size_t	mul;
	char	*res;
	size_t	i;

	mul = num * size;
	if (num != 0 && mul / num != size)
		return (0);
	res = (char *) malloc(mul);
	if (!res)
		return (0);
	i = 0;
	while (i < mul)
		res[i++] = 0;
	return (res);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	ft_strjoin_gnl(char **s1, char *s2, size_t s2_len)
{
	char	*res;
	size_t	i;
	size_t	s1_len;

	if (s2_len == 0)
		return ;
	s1_len = ft_strlen_gnl(*s1);
	res = (char *) ft_calloc_gnl(s1_len + s2_len + 1, sizeof(char));
	if (!res)
	{
		free(*s1);
		*s1 = 0;
		return ;
	}
	i = -1;
	while (++i < s1_len)
		res[i] = (*s1)[i];
	i = -1;
	while (++i < s2_len)
		res[s1_len + i] = s2[i];
	free(*s1);
	*s1 = res;
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;
	size_t	total_len;

	if (!s)
		return (0);
	s_len = ft_strlen_gnl(s);
	if (start >= s_len)
		return (0);
	else if (s_len - start < len)
		total_len = s_len - start;
	else
		total_len = len;
	res = (char *) ft_calloc_gnl(total_len + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && i + start < s_len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*res;
	int		len;
	int		i;

	if (!s1)
		return (0);
	len = ft_strlen_gnl(s1);
	res = (char *) ft_calloc_gnl(len + 1, sizeof(char));
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
