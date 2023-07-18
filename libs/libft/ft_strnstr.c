/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:34:56 by jdomingu          #+#    #+#             */
/*   Updated: 2022/05/05 20:58:09 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	s;

	s = 0;
	if (needle[0] == '\0' || needle == 0)
		return ((char *) haystack);
	while (haystack[s] != '\0' && s < len)
	{
		n = 0;
		while (haystack[s + n] == needle[n] && (s + n) < len)
		{
			n++;
			if (needle[n] == '\0')
				return ((char *) haystack + s);
		}
		s++;
	}
	return (0);
}
