/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:57:32 by jdomingu          #+#    #+#             */
/*   Updated: 2022/05/05 20:11:58 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = ft_nlen(n);
	str = (char *) malloc ((nlen + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[nlen] = '\0';
	nlen--;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[nlen] = (n % 10) + '0';
		n = n / 10;
		nlen--;
	}
	return (str);
}
