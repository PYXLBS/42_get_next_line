#include "get_next_line.h"

static int	ft_read_all(int fd, char **buffer)
{
	char	*temp_var;
	char	*temp_buffer;
	int		bytes_read;

	temp_var = ft_calloc((BUFFER_SIZE + 1), 1);
	if ((buffer == NULL) || (temp_var == NULL))
		return (-1);
	bytes_read = read(fd, temp_var, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp_var);
		return (bytes_read);
	}
	temp_var[bytes_read] = '\0';
	if (*buffer != NULL)
	{
		temp_buffer = ft_strjoin(*buffer, temp_var);
		free(*buffer);
		*buffer = temp_buffer;
	}
	else
		*buffer = ft_strjoin("", temp_var);
	free(temp_var);
	return (bytes_read);
}

static int	ft_update_all(char **buffer, char **line)
{
	char	*chr;
	char	*temp_buffer;

	if (*buffer == NULL)
		return (0);
	chr = ft_strchr(*buffer, '\n');
	if (chr != NULL)
	{
		if (chr == *buffer)
		{
			*line = ft_calloc(2, 1);
			if (*line == NULL)
				return (-1);
			(*line)[0] = '\n';
			temp_buffer = ft_strjoin(chr + 1, "");
			free(*buffer);
			*buffer = temp_buffer;
		}
		else
		{
			*line = ft_calloc(chr - *buffer + 2, 1);
			if (*line == NULL)
				return (-1);
			ft_strlcat(*line, *buffer, chr - *buffer + 1);
			(*line)[chr - *buffer] = '\n';
			temp_buffer = ft_strjoin(chr + 1, "");
			free(*buffer);
			*buffer = temp_buffer;
		}
		if (*buffer != NULL && *buffer[0] == '\0')
		{
			free(*buffer);
			*buffer = NULL;
		}
		return (1);
	}
	else
	{
		*line = ft_strjoin(*buffer, "");
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
}

static char	*reset_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (*buffer);
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
		bytes_read = ft_read_all(fd, &buffer);
		if (bytes_read <= 0)
		{
			if (bytes_read == -1)
				return (reset_buffer(&buffer));
			break ;
		}
	}
	if (bytes_read == 0 && *buffer == '\0')
		return (reset_buffer(&buffer));
	line = NULL;
	if (ft_update_all(&buffer, &line) == -1)
		return (reset_buffer(&buffer));
	return (line);
}
