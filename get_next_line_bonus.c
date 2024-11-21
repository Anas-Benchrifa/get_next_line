/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:47:16 by mac               #+#    #+#             */
/*   Updated: 2024/11/21 13:30:58 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*scanner_lines(char *line, int fd)
{
	char	*_line;
	int		scanner_line;

	_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!_line)
		return (NULL);
	scanner_line = 1;
	while (!check_new_line(line) && scanner_line != 0)
	{
		scanner_line = read(fd, _line, BUFFER_SIZE);
		if (scanner_line == -1)
		{
			free(line);
			free(_line);
			return (NULL);
		}
		_line[scanner_line] = '\0';
		line = ft_strjoin(line, _line);
	}
	free(_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX + 1];
	char		*x_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = scanner_lines(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	x_line = _get_line(buffer[fd]);
	buffer[fd] = save_next_line(buffer[fd]);
	return (x_line);
}
