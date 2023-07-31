/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:26:09 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/09 20:26:16 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*ft_gnl_strdup(char *str);
void	ft_gnl_strjoin(char **str1, char *str2, size_t s2len);
size_t	ft_gnl_strlen(char *str);
void	*ft_gnl_calloc(size_t count, size_t size);
#endif
