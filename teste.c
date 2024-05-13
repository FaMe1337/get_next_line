#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char	buf[256];
	int chars_count;

	fd = open("text.txt", O_RDONLY);

	while((chars_count = read(fd, buf, 10)))
	{
		buf[chars_count] = '\0';
		printf("buf -> %s\n", buf);
	}
}
