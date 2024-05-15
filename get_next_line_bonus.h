/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:45 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/15 23:55:25 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*check_newline(char **leftover);
char	*read_and_join(int fd, char **leftover);
char	*finalize_line(char **leftover);
char	*handle_read(char *buf, char **leftover);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dst, char *src);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif