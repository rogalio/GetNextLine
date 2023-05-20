/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:01:37 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/20 17:21:24 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




/*

char *get_next_line(int fd)
{
	char			*buf;
	static char 	*line;
	ssize_t			ret;
	char			*tmp;
	char			*newline_ptr;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		
	if (line == NULL)
	{
		line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
		
	while ((newline_ptr = ft_strchr(line, '\n')) == NULL)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
			
		buf[ret] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
	}
	
	free(buf);
	
	if (ret == 0 || (ret == 0 && line[0] == '\0'))
		return NULL;
		
	if (newline_ptr == NULL)
        newline_ptr = ft_strchr(line, '\0');

    tmp = ft_substr(line, 0, newline_ptr - line);
    memmove(line, newline_ptr + 1, ft_strlen(newline_ptr + 1) + 1);
    return tmp;
}
*/

/*
char *get_next_line(int fd)
{
	char			*buf;
	static char 	*line;
	ssize_t			ret;
	char			*tmp;
	char			*newline_ptr;
	
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while ((newline_ptr = ft_strchr(line, '\n')) == NULL && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);  // free line here, after using it in ft_strjoin
		line = tmp;
	}
	free(buf);
	if (ret == 0)
		return (NULL);

	// Need to handle the rest of the line
	tmp = line;
	line = ft_substr(line, 0, newline_ptr - line);
	free(tmp);
	return (line);
}

*/

static char	*function_name(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract_line(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char *get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *backup;
	
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = function_name(fd,buf,backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract_line(line);
	return (line);
}



/*
int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
*/
