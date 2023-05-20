/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:02:09 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/20 17:15:01 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// buffur default size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>




char 	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(const char *s1,const char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif