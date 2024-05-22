/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:34:28 by famendes          #+#    #+#             */
/*   Updated: 2024/05/20 19:09:08 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

/* #ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
 */
//fuctions to get next line
char	*get_next_line(int fd);
char	*create_string(char *str, int fd);
char	*copy_to_line(char *str_read);
char	*missing_char(char *str);

//utilities
int		my_strchr(char *s, int c);
char	*str_join(char *buf, char *str_read);
int		str_len(char *str);

#endif