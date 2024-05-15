/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/05/15 20:49:26 by famendes         ###   ########.fr       */
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
	i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[i] = '\0';
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
	return (str);
}

char	*create_string(char *str, int fd)
{
	char	*buf;
	int	char_read;
	
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!my_strchr(str, '\n'))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return(NULL);
		}
		buf[char_read] = '\0';
		str = str_join(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str_read;
	char *next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	str_read = create_string(str_read, fd);
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
    if((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
    }
	free(line);
}