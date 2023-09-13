#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i = 0;
	int		number_of_lines = 15;
	char	*str;

	fd = open("./gnl.txt", O_RDONLY);
	if (fd >= 0)
	{
		while (i < number_of_lines)
		{
			str = get_next_line(fd);
			printf("RESULT Line %d = %s", i + 1, str);
			if (i < number_of_lines)
				free(str);
			i++;
		}
		close(fd);
	}
	return (0);
}
