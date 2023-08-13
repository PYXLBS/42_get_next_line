#include "get_next_line.h"

static char	*free_reset_return(char **to_res, char *res_to, char *to_ret)
{
	free(*to_res);
	*to_res = res_to;
	return (to_ret);
}

static int	read_all(int fd, char **buffer)
{
	char	*temp_var;
	char	*temp_buffer;
	int		bytes_read;

	temp_var = ft_calloc((BUFFER_SIZE + 1), 1);
	if (buffer == NULL || temp_var == NULL)
		return (-1);
	bytes_read = read(fd, temp_var, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free_reset_return(&temp_var, NULL, NULL);
		return (bytes_read);
	}
	temp_var[bytes_read] = '\0';
	if (*buffer != NULL)
	{
		temp_buffer = ft_strjoin(*buffer, temp_var);
		free_reset_return(buffer, temp_buffer, NULL);
	}
	else
		*buffer = ft_strjoin("", temp_var);
	free_reset_return(&temp_var, NULL, NULL);
	return (bytes_read);
}

static int	handle_newline(char **buffer, char **line, char *chr)
{
	char	*temp_buffer;

	if (chr == *buffer)
	{
		*line = ft_calloc(2, 1);
		if (*line == NULL)
			return (-1);
		(*line)[0] = '\n';
		temp_buffer = ft_strjoin(chr + 1, "");
		free_reset_return(buffer, temp_buffer, NULL);
	}
	else
	{
		*line = ft_calloc(chr - *buffer + 2, 1);
		if (*line == NULL)
			return (-1);
		ft_strlcat(*line, *buffer, chr - *buffer + 1);
		(*line)[chr - *buffer] = '\n';
		temp_buffer = ft_strjoin(chr + 1, "");
		free_reset_return(buffer, temp_buffer, NULL);
	}
	if (*buffer != NULL && *buffer[0] == '\0')
		free_reset_return(buffer, NULL, NULL);
	return (1);
}

static int	update_all(char **buffer, char **line)
{
	char	*chr;

	if (*buffer == NULL)
		return (0);
	chr = ft_strchr(*buffer, '\n');
	if (chr != NULL)
		return (handle_newline(buffer, line, chr));
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
