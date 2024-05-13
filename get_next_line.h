/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:57:53 by famendes          #+#    #+#             */
/*   Updated: 2024/05/13 18:27:53 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

// node to have the string to be written
typedef struct s_list
{
	char			*str;
	struct s_list	*next;
} t_list;

//fuctions to get next line
char	*get_next_line(int fd);
void	create_list(t_list **lst, int fd);
char *get_line(t_list *lst);
void	polish_list(t_list **lst);

//utilities
int	new_line(t_list *lst);
void lst_add_buf(t_list *lst, char *str);
t_list *lst_find_last(t_list **lst);
int ft_len(t_list *lst);
void	free_all(t_list **lst);

#endif