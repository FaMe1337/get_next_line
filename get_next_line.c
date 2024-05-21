/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/05/21 23:14:09 by fabio            ###   ########.fr       */
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
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = malloc(str_len(str) - i + 1);
	if (!new)
		return (NULL);
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
	char *str;

	i = 0;
	if (!str_read[i])
		return (NULL);
	str = malloc(str_len(str_read) + 2);
	if (!str)
		return (NULL);
	while (str_read[i])
	{
		if(str_read[i] == '\n')
		{
			str[i++] = '\n';
			str[i] = '\0';
			return (str);
		}	
		str[i] = str_read[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*create_string(char *str, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int	char_read;
	
	char_read = 1;
	while (!my_strchr(str, '\n'))
	{	
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
			return(NULL);
		buf[char_read] = '\0';
		str = str_join(buf, str);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str_read;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_read = create_string(str_read, fd);
	if (!str_read)
		return (NULL);
	line = copy_to_line(str_read);
	str_read = missing_char(str_read);
	return (line);
}

/* int main() {
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
   while ((line = get_next_line(fd)) != NULL) {
        printf("main print: %s\n", line);
		free(line);
    }
} */