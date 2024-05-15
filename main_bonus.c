#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
// Bonus part
	int fd1 = open("file_bonus1.txt", O_RDONLY);
	int fd2 = open("file_bonus2.txt", O_RDONLY);
	int fd3 = open("file_bonus3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Failed to open file.\n");
		return (1);
	}
	char *line1 = NULL;
	char *line2 = NULL;
	char *line3 = NULL;
	while (((line1 = get_next_line(fd1)) != NULL)|| ((line2 = get_next_line(fd2)) != NULL) || ((line3 = get_next_line(fd3)) != NULL))
	{
		if (line1 != NULL)
		{
			printf("%s", line1);
			free(line1);
		}
		if (line2 != NULL)
		{
			printf("%s", line2);
			free(line2);
		}
		if (line3 != NULL)
		{
			printf("%s", line3);
			free(line3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}