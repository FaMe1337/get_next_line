/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/05/18 14:21:29 by fabio            ###   ########.fr       */
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
	ssize_t	char_read;
	
	char_read = 1;
	printf("str before cycle: %s\n",str);
	printf("char_read before cycle read: %d\n",str_len(buf));
	while (char_read > 0 && !my_strchr(str, '\n'))
	{	
		char_read = read(fd, buf, BUFFER_SIZE);
		printf("buf after read: %s\n", buf);
		printf("char_read in cycle read: %d\n",str_len(buf));
		if (char_read == 0)
			return(NULL);
		buf[char_read] = '\0';
		printf("str before join: %s\n", str);
		str = str_join(buf, str);
		printf("str after join: %s\n", str);
		if (char_read == 0)
			break;
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
	printf("str_read before create_string: %s\n",str_read);	
	str_read = create_string(str_read, fd);
	printf("str_read after: %s\n",str_read);
	if (!str_read)
		return (NULL);
	next_line = copy_to_line(str_read);
	printf("next_line after cpy: %s\n",next_line);
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