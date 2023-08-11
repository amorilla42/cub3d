/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:36:27 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/11 18:41:21 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(char *s1);
void	ft_strjoin_gnl(char **s1, char *s2, size_t s2_len);
void	*ft_calloc_gnl(size_t count, size_t size);
size_t	ft_strlen_gnl(char *s);
char	*get_next_line(int fd);
#endif
