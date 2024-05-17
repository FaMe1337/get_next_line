/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/05/17 01:31:23 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*missing_char(char *str)
{
	int	i;
	int	j;
	char	*new;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	new = malloc(str_len(str) - i + 1);
	printf("size of malloc in missing char: %d\n",str_len(str) - i + 1);
	if (!new)
		return (NULL);
	if (*str != '\n')
		i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
 	free(str);
	return(new);
}

char	*copy_to_line(char *str_read)
{
	int	i;
	int	j;
	char *str;
	printf("copy str_read: %s\n",str_read);

	i = 0;
	j = 0;
	str = malloc(str_len(str_read) + 1);
	if (!str)
		return (NULL);
	while (str_read[i])
	{
		if(str_read[i] == '\n')
		{
			str[j++] = '\n';
			str[j] = '\0';
			return(str);
		}
		str[j++] = str_read[i++];
	}
	str[j] = '\0';
	return (str);
}

char	*create_string(char *str, int fd)
{
	char	buf[BUFFER_SIZE];
	int	char_read;
	
	char_read = 1;
	printf("str before cycle: %s\n",str);
	while (char_read > 0 && !my_strchr(str, '\n'))
	{	
		char_read = read(fd, buf, BUFFER_SIZE);
		printf("buf after read: %s\n", buf);
		if (char_read <= 1)
			return(NULL);
		buf[char_read] = '\0';
		str = str_join(buf, str);
		//tenho de ver condiçao de paragem char_read=2 ultima leitura
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str_read = NULL;
	char *next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	str_read = create_string(str_read, fd);
	printf("str_read: %s\n",str_read);
	if (!str_read)
		return (NULL);
	next_line = copy_to_line(str_read);
	str_read = missing_char(str_read);
	return (next_line);
}
int main() {
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while((line = get_next_line(fd)) != NULL) {
        printf("main print: %s\n", line);
		free(line);
    }
}