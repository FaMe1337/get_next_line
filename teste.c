#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the BUFFER_SIZE for consistency
#define BUFFER_SIZE 10

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_join(char *buf, char *str_read)
{
	int	i;
	int j;
	char *cpy;
	
	i = 0;
	j = 0;
	if (!str_read)
	{
		str_read = malloc(1);
		str_read[0] = '\0';
	}
	cpy = malloc(str_len(buf) + str_len(str_read) + 1);
	if (!cpy)
		return (NULL);
	while (str_read[j])
		cpy[i++] = str_read[j++];
	j = 0;
	while (buf[j])
		cpy[i++] = buf[j++];
	cpy[i] = '\0';
	return (cpy);
}

int main()
{
	char	*s1 = "";
	char	*s2 = "tudo bem";

	printf("%s\n", str_join(s2, s1));
}