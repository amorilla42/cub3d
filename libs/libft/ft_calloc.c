/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:41:23 by jdomingu          #+#    #+#             */
/*   Updated: 2022/05/05 20:07:13 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	mult;

	mult = count * size;
	ptr = malloc(mult);
	if (!ptr || (count != 0 && mult / count != size))
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
