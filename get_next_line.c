/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:34:51 by mac               #+#    #+#             */
/*   Updated: 2024/11/20 20:20:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;
	char		*x_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = scanner_lines(buffer, fd);
	if (!buffer)
		return (NULL);
	x_line = _get_line(buffer);
	buffer = save_next_line(buffer);
	return (x_line);
}
