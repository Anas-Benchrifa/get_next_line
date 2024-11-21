/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:33:33 by mac               #+#    #+#             */
/*   Updated: 2024/11/21 13:48:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	check_new_line(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	index_s1;
	size_t	index_s2;
	char	*join;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char ));
		s1[0] = '\0';
	}
	index_s1 = -1;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[++index_s1])
		join[index_s1] = s1[index_s1];
	index_s2 = 0;
	while (s2[index_s2])
		join[index_s1++] = s2[index_s2++];
	join[index_s1] = '\0';
	free(s1);
	return (join);
}

char	*_get_line(char *line)
{
	char	*_line;
	int		index_l;

	index_l = 0;
	if (!line[index_l])
		return (NULL);
	while (line[index_l] && line[index_l] != '\n')
		index_l++;
	if (line[index_l] == '\n')
		index_l++;
	_line = (char *)malloc((index_l + 1) * sizeof(char ));
	if (!_line)
		return (NULL);
	index_l = -1;
	while (line[++index_l] && line[index_l] != '\n')
		_line[index_l] = line[index_l];
	if (line[index_l] == '\n')
	{
		_line[index_l] = line[index_l];
		index_l++;
	}
	_line[index_l] = '\0';
	return (_line);
}

char	*save_next_line(char *save)
{
	char	*_save;
	int		_index;
	int		index;

	index = 0;
	_index = 0;
	while (save[index] && save[index] != '\n')
		index++;
	if (!save[index])
	{
		free(save);
		return (NULL);
	}
	if (save[index] == '\n')
		index++;
	_save = (char *)malloc((ft_strlen(save) - index) + 1);
	if (!_save)
		return (NULL);
	while (save[index])
		_save[_index++] = save[index++];
	_save[_index] = '\0';
	free(save);
	return (_save);
}
