/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:24:32 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 22:51:30 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int ind, int fd);
int		read_file(int fd, char **s_str, char **buffer, char **line);
void	get_line(char	**line, char **s_str);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
void	free_ptr(char *str);

#endif