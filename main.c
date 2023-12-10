
// #include "get_next_line.h"
// #include <sys/fcntl.h>
// int main()
// {
// 	char *line;

// 	int fd = open("Makefile", O_RDWR);
// 	line = get_next_line(fd);
// 		printf("line = %s", line);

// 	while(line)
// 	{
// 		printf("line = %s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }
