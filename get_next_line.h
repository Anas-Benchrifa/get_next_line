/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:34:24 by mac               #+#    #+#             */
/*   Updated: 2024/11/20 18:27:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
int		check_new_line(char *s);
char	*save_next_line(char *save);
size_t	ft_strlen(char *s);
char	*_get_line(char *line);
char	*get_next_line(int fd);

#endif