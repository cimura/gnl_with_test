#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	// Mandatory part
	int fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file.\n");
		return (1);
	}
	char *line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}