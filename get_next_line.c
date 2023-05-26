/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:01:37 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/26 18:58:48 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	process_buffer(int fd, char *buf, char **str_vault)
{
	ssize_t	byte;
	char	*tmp;

	while (ft_strchr(buf, '\n') == NULL)
	{	
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte != -1)
			buf[byte] = '\0';
		if (byte == 0 || byte == -1)
			return (false);
		tmp = ft_strjoin(*str_vault, buf);
		free(*str_vault);
		*str_vault = tmp;
	}
	return (true);
}

int	get_newline_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	char		*line_to_return;
	char		*str_vault;
	int			newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	str_vault = ft_strdup(buf);
	if (!process_buffer(fd, buf, &str_vault) && str_vault[0] == '\0')
	{
		free(str_vault);
		return (NULL);
	}
	newline_pos = get_newline_pos(str_vault);
	if (ft_strchr(buf, '\n'))
	{
		line_to_return = ft_substr(str_vault, 0, newline_pos + 1);
		ft_strcpy(buf, str_vault + newline_pos + 1);
		free(str_vault);
		return (line_to_return);
	}
	return (str_vault);
}

/*
int main(int argc, char **argv)
{
	int fd;
	char *line;

	//fd = open("test.txt", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	
	return (0);
}
*/
