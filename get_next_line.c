/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:57:50 by famendes          #+#    #+#             */
/*   Updated: 2024/05/13 18:30:02 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **lst)
{
	int	i;
	int j;
	t_list *node;
	t_list *last_node;

	j = 0;
	i = 0;
	last_node = lst_find_last(lst);
	node = malloc(sizeof(t_list));
	if (!node)
		return;
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	i++;
	while (last_node->str[i])
		node->str[j++] = last_node->str[i++];
	node->str[j] = '\0';
	node->next = NULL;
	free_all(&lst);
	*lst = node;
}

char *get_line(t_list *lst)
{
	char *str;
	int	i;
	int j;

	str = malloc(ft_len(lst) + 1); // allocation for string
	if (!str)
		return (NULL);
	while (lst) //coyping from lst to the string
	{
		j = 0;
		while (lst->str[i])
		{
			i = 0;
			if (lst->str[i] == '\n') //stop cpy at \n sign
			{
				str[j++] = '\n';
				str[j] = '\0';
				return (str);
			}	
			str[j++] = lst->str[i++];
		}
		lst = lst->next;
	}
	str[j] = '\0';
	return (str);
}

void	create_list(t_list **lst, int fd)
{
	int	char_read;
	char	*buf;
	//verification if an \n exists
	while (!new_line(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return;
		//read buffer_size bytes of text into buf
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{	
			free(buf);
			return;
		}	
		buf[char_read] = '\0';
		//add the part read into the lst
		lst_add_buf(&lst, buf);
		free(buf);
	}
}

char	*get_next_line(int fd)
{
	static	t_list *lst = NULL;
	char	*next_line;
	// verifications
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0) 
		return (NULL);
	//creating list until i have encounter a \n
	create_list(&lst, fd);
	if (!lst)
		return (NULL);
	//copying from lst to buf
	next_line = get_line(lst);
	//freeing the lst for the next cycle
	polish_list(&lst);
	return (next_line);
}
