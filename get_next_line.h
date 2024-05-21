/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:57:53 by famendes          #+#    #+#             */
/*   Updated: 2024/05/21 23:13:40 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

//fuctions to get next line
char	*get_next_line(int fd);
char	*create_string(char *str, int fd);
char	*copy_to_line(char *str_read);
char	*missing_char(char *str);

//utilities
char	*my_strchr(char *s, int c);
char	*str_join(char *buf, char *str_read);
int	str_len(const char *str);

#endif