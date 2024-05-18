/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:22 by famendes          #+#    #+#             */
/*   Updated: 2024/05/17 22:45:00 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if(!s)
		return 0;
	while (s[i])
	{
		if (s[i] == (char)c)
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
		cpy = malloc(str_len(buf) + 1);
	} else{
		cpy = malloc(str_len(buf) + str_len(str_read) + 1);
	}
	
	if (!cpy)
		return (NULL);
		
	while (str_read && str_read[j])
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

	if(!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
