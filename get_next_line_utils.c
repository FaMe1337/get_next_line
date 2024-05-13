/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:57:47 by famendes          #+#    #+#             */
/*   Updated: 2024/05/13 18:28:19 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(t_list *lst)
{
	int	i;

	if (!lst)
		return (1);
	while (lst)
	{
		i = 0;
		while (lst->str[i] && i < BUFFER_SIZE)
		{
			if (lst->str[i] == '\n')
				return (1);
			i++;
		}	
		lst = lst->next;
	}
	return (0);
}

void lst_add_buf(t_list **lst, char *str)
{
	t_list *new_node;
	t_list *last_node;

	last_node = lst_find_last(&lst);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return;
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->str = str;
	new_node->next = NULL;
}

t_list	*lst_find_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
int ft_len(t_list *lst)
{
	int	i;
	
	if (!lst)
		return (0);
	while (lst)
	{	
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
					return (i++);
			i++;
		}
		lst = lst->next;
	}
	return (i);
}
void	free_all(t_list **lst)
{
	t_list *current;
	
	while (*lst)
	{	
		current = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = current;
	}
	free (*lst);
	return;
}