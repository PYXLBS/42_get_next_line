/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:21:58 by pabertha          #+#    #+#             */
/*   Updated: 2023/09/20 13:21:59 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_reset_return(char *to_reset, char *reset_to, char *to_return)
{
	if (to_reset != NULL)
		free(to_reset);
	to_reset = reset_to;
	return (to_return);
}

void	update_all(char *buffer, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i] != '\0')
	{
		buffer[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	line = NULL;
	line = ft_strjoin(line, buffer);
	while (ft_strchr(buffer, '\n') == NULL && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_reset_return(line, NULL, NULL));
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (line);
	}
	if (line[0] == '\0')
		return (free_reset_return(line, NULL, NULL));
	update_all(buffer, line);
	return (line);
}
