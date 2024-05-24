/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:22 by famendes          #+#    #+#             */
/*   Updated: 2024/05/24 16:28:18 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (++i);
	return (i);
}

void	ft_clean_buf(char *buf)
{
	int	i;
	int	l;
	int	j;

	i = ft_strlen(buf) - 1;
	j = 0;
	l = 0;
	while (buf[l])
		l++;
	buf[i++] = '\0';
	while (i < l)
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	s_res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			s_res[i] = s1[i];
			i++;
		}
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
		s_res[i++] = s2[j++];
	s_res[i] = '\0';
	if (s1)
		free(s1);
	ft_clean_buf(s2);
	return (s_res);
}

int	chrnline(char *s)
{
	while (*s != '\0' && *s != '\n')
		s++;
	if (*s == '\n')
		return (1);
	return (0);
}
