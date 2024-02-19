/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:38 by ichpakov          #+#    #+#             */
/*   Updated: 2023/12/04 08:06:12 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*temp[1024];
	char			buffer[BUFFER_SIZE + 1];
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp), temp = NULL, NULL);
	if (have_n(temp))
		return (print_line(&temp));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		temp = ft_strjoin(temp, &buffer);
		if (have_n(temp))
			break ;
	}
	return (print_line(&temp));
}
