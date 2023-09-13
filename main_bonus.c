#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		number_of_lines = 20;
	char	*str;

	fd = open("./gnl_1.txt", O_RDONLY);
	fd2 = open("./gnl_2.txt", O_RDONLY);
	fd3 = open("./gnl_3.txt", O_RDONLY);
	if (fd >= 0)
	{
		while (i < number_of_lines)
		{
			str = get_next_line(fd);
			printf("FD 1 RESULT Line %d = %s", i++, str);
			if (i < number_of_lines)
				free(str);
			str = get_next_line(fd2);
			printf("FD 2 RESULT Line %d = %s", j++, str);
			if (i < number_of_lines)
				free(str);
			str = get_next_line(fd3);
			printf("FD 3 RESULT Line %d = %s", k++, str);
			if (i < number_of_lines)
				free(str);
		}
		close(fd);
	}
	return (0);
}
