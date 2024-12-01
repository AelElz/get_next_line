/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:32:52 by ael-azha          #+#    #+#             */
/*   Updated: 2024/12/01 16:57:47 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	ft_read_file(int fd, char *buffer)
{
	char	*holder;
	int		byte_read;

	if (!buffer)
		ft_calloc(1, 1);
	holder = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, holder, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(holder);
			return (NULL);
		}
		holder[byte_read] = 0;
		buffer = ft_free(holder, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(holder);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!fd || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
}
