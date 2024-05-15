/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:57:53 by famendes          #+#    #+#             */
/*   Updated: 2024/05/15 20:33:59 by famendes         ###   ########.fr       */
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

//fuctions to get next line
char	*get_next_line(int fd);
char	*create_string(char *str, int fd);
char	*copy_to_line(char *str_read);
char	*missing_char(char *str);

//utilities
int	my_strchr(char *str, int c);
char	*str_join(char *buf, char *str_read);
int	str_len(char *str);


#endif