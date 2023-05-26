/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:03:51 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/26 18:56:43 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{	
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
