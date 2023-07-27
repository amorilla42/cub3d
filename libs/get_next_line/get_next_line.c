/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:25:40 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/09 20:25:50 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_eol(char *buff, int *pos)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			*pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_read_fd(int fd, char *buff, char **line, int *eol_idx)
{
	int		nbytes;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buff[i++] = 0;
	nbytes = read(fd, buff, BUFFER_SIZE);
	if (nbytes == -1)
		return (-1);
	if (ft_find_eol(buff, eol_idx))
		ft_gnl_strjoin(line, buff, ((size_t)(*eol_idx)) + 1);
	else
	{
		ft_gnl_strjoin(line, buff, ft_gnl_strlen(buff));
		*eol_idx = -1;
	}
	return (nbytes);
}

static int	ft_check_buff(char **static_buff, char **line)
{
	int		i;
	char	*tmp;

	if (!*static_buff)
	{
		*line = 0;
		return (0);
	}
	if (ft_find_eol(*static_buff, &i))
	{
		*line = ft_gnl_substr(*static_buff, 0, i + 1);
		tmp = *static_buff;
		*static_buff = ft_gnl_substr(tmp, i + 1, ft_gnl_strlen(*static_buff));
		free(tmp);
		return (1);
	}
	*line = ft_gnl_strdup(*static_buff);
	free(*static_buff);
	*static_buff = 0;
	return (0);
}

static char	*ft_getline(int fd, char *buff, char **static_buff)
{
	char	*line;
	int		nbytes;
	int		eol_idx;

	if (ft_check_buff(static_buff, &line))
		return (line);
	nbytes = 1;
	eol_idx = -1;
	while (nbytes && eol_idx == -1)
	{
		nbytes = ft_read_fd(fd, buff, &line, &eol_idx);
		if (nbytes == -1 || !line)
		{
			free(line);
			return (0);
		}
	}
	free(*static_buff);
	*static_buff = 0;
	if (eol_idx == -1)
		ft_gnl_strjoin(&line, buff, ft_gnl_strlen(buff));
	else
		*static_buff = ft_gnl_substr(buff, (size_t) eol_idx + 1,
				ft_gnl_strlen(buff));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_buff[1024];
	char		*buff;
	char		*line;

	line = 0;
	if (BUFFER_SIZE > 0 && fd >= 0 && fd < 1024)
	{
		buff = (char *) ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buff)
		{
			line = ft_getline(fd, buff, &(static_buff[fd]));
			free(buff);
		}
	}
	return (line);
}
