#include "get_next_line.h"

static char	*free_reset_return(char **to_reset, char *reset_to, char *to_return)
{
	free(*to_reset);
	*to_reset = reset_to;
	return (to_return);
}

static int	read_all(int fd, char **buffer)
{
	char	*new_data;
	int		bytes_read;
	char	*joined_buffer;

	new_data = ft_calloc((BUFFER_SIZE + 1), 1);
	if (buffer == NULL || new_data == NULL)
		return (-1);
	bytes_read = read(fd, new_data, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free_reset_return(&new_data, NULL, NULL);
		return (bytes_read);
	}
	new_data[bytes_read] = '\0';
	if (*buffer != NULL)
	{
		joined_buffer = ft_strjoin(*buffer, new_data);
		free_reset_return(buffer, joined_buffer, NULL);
	}
	else
		*buffer = ft_strjoin("", new_data);
	free_reset_return(&new_data, NULL, NULL);
	return (bytes_read);
}

static int	handle_newline(char **buffer, char **line, char *newline)
{
	char	*joined_buffer;

	if (newline == *buffer)
	{
		*line = ft_calloc(2, 1);
		if (*line == NULL)
			return (-1);
		(*line)[0] = '\n';
		joined_buffer = ft_strjoin(newline + 1, "");
		free_reset_return(buffer, joined_buffer, NULL);
	}
	else
	{
		*line = ft_calloc(newline - *buffer + 2, 1);
		if (*line == NULL)
			return (-1);
		ft_strlcat(*line, *buffer, newline - *buffer + 1);
		(*line)[newline - *buffer] = '\n';
		joined_buffer = ft_strjoin(newline + 1, "");
		free_reset_return(buffer, joined_buffer, NULL);
	}
	if (*buffer != NULL && *buffer[0] == '\0')
		free_reset_return(buffer, NULL, NULL);
	return (1);
}

static int	update_all(char **buffer, char **line)
{
	char	*newline;

	if (*buffer == NULL)
		return (0);
	newline = ft_strchr(*buffer, '\n');
	if (newline != NULL)
		return (handle_newline(buffer, line, newline));
	else
	{
		*line = ft_strjoin(*buffer, "");
		free_reset_return(buffer, NULL, NULL);
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;
	char		*line;

	if (buffer == NULL)
		buffer = ft_calloc(1, 1);
	while (buffer != NULL && ft_strchr(buffer, '\n') == NULL)
	{
		bytes_read = read_all(fd, &buffer);
		if (bytes_read <= 0)
		{
			if (bytes_read == -1)
				return (free_reset_return(&buffer, NULL, NULL));
			break ;
		}
	}
	if (bytes_read == 0 && *buffer == '\0')
		return (free_reset_return(&buffer, NULL, NULL));
	line = NULL;
	if (update_all(&buffer, &line) == -1)
		return (free_reset_return(&buffer, NULL, NULL));
	return (line);
}
