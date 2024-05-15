/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:22 by famendes          #+#    #+#             */
/*   Updated: 2024/05/15 20:26:13 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int my_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
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
	if (!str_read || !buf)
		return (NULL);
	cpy = malloc(str_len(buf) + str_len(str_read) + 1);
	if (!cpy)
		return (NULL);
	while (str_read[j])
		cpy[i++] = str_read[j++];
	j = 0;
	while (buf[j])
		cpy[i++] = buf[j++];
	cpy[i] = '\0';
	free(str_read);
	return (cpy);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
