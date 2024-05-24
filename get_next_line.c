/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:07 by famendes          #+#    #+#             */
/*   Updated: 2024/05/24 16:27:33 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i == -1 || i == 0)
				return (result);
			buf[i] = '\0';
		}
		result = ft_strjoin(result, buf);
		if (chrnline(result))
			break ;
	}
	return (result);
}

/* int main()
{
	char *line;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
} */