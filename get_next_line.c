/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:01:37 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/24 19:05:32 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


bool read_file(int fd, char *buf, char **str_vault)
{
	ssize_t byte;
	
	while ((byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = '\0';
		char *temp = ft_strjoin(*str_vault, buf);
		free(*str_vault);
		*str_vault = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (byte == -1)
		return (false);
	if (byte == 0 && !ft_strlen(*str_vault))
		return (false);
	return (true);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	char		*line_to_return;
	char		*str_vault;
	int			i;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_vault = ft_strdup(buf);
	if (!read_file(fd, buf, &str_vault))
	{
		free(str_vault);
		return (NULL);
	}
	i = 0;
	while (str_vault[i] && str_vault[i] != '\n')
		i++;
	line_to_return = ft_substr(str_vault, 0, i + 1);
	if (str_vault[i] == '\n')
	{
		ft_strcpy(buf, str_vault + i + 1);
		free(str_vault);
		return (line_to_return);
	}
	ft_strcpy(buf, str_vault + i);
	free(str_vault);
	return (line_to_return);
}



/*


int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	
	return (0);
}
*/