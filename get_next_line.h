/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:02:09 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/24 18:43:36 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// buffur default size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char 	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(const char *s1,const char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);


#endif