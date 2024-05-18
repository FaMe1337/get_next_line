/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:05:40 by fabio             #+#    #+#             */
/*   Updated: 2024/05/18 20:25:09 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (!my_strchr(str, '\n') && char_read > 0)
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
	static char	*str_read[4096];
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (NULL);
	str_read[fd] = create_string(str_read[fd], fd);
	if (!str_read[fd])
		return (NULL);
	next_line = copy_to_line(str_read[fd]);
	str_read[fd] = missing_char(str_read[fd]);
	return (next_line);
}