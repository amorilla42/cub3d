/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:45:48 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:45:49 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_file(char *file, t_data *data)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	while (read(data->fd, &aux, 1) > 0)
	{
		if (aux == '\n')
			i++;
	}
	close(data->fd);
	data->file = ft_calloc(sizeof(char *), i + 1);
	if (!data->file)
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	data->fd = open(file, O_RDONLY);
	j = 0;
	while (j < i)
	{
		data->file[j] = get_next_line(data->fd);
		j++;
	}
	close(data->fd);
}
