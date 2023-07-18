/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:46:14 by jdomingu          #+#    #+#             */
/*   Updated: 2022/05/05 20:58:41 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_onset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (s1[i] != '\0' && ft_onset(s1[i], set))
		i++;
	if (i - 1 == j)
		return (ft_strdup(""));
	while (j != 0 && ft_onset(s1[j], set))
		j--;
	str = (char *) ft_calloc((j - i + 2), sizeof(char));
	if (!str)
		return (0);
	while (i <= j)
		str[k++] = s1[i++];
	return (str);
}
