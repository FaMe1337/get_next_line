/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/05/21 12:59:29 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*missing_char(char *str)
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
	static char	buf[BUFFER_SIZE + 1];
	char	*str_read;
	char *next_line;
	int	char_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char_read = 1;
	while (!(str_read = my_strchr(next_line, '\n')) && 
	(char_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (char_read == -1)
			return(NULL);
		buf[char_read] = '\0';
		str_read = str_join(buf, str_read);
	}
	if (!str_read)
		return (NULL);
	next_line = copy_to_line(str_read);
	str_read = missing_char(str_read);
	return (next_line);
} */

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)	
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(const char *src)
{
	size_t	len = ft_strlen(src) + 1;
	char	*dst = malloc(len);
	
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len = ft_strlen(s1);
	size_t	s2_len = ft_strlen(s2);
	char	*join = malloc((s1_len + s2_len + 1));

	if (!s1 || !s2)
		return (NULL);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + s1_len), s2);
	free(s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (/* ft_strlen(line) == 0 */!line[0]) 
		return (free(line), NULL);

	if (newline)
	{
		to_copy = newline - line + 1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buf[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}
int main() {
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    if ((line = get_next_line(fd)) != NULL) {
        printf("main print: %s\n", line);
		free(line);
    }
}