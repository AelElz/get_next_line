/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:32:52 by ael-azha          #+#    #+#             */
/*   Updated: 2024/12/05 17:45:29 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *buffer, char *holder)
{
	char	*join;

	join = my_strjoin(buffer, holder);
	free(buffer);
	return (join);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*holder;
	int		byte_read;

	if (!buffer)
		buffer = my_calloc(1, 1);
	holder = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!holder)
		return (free(buffer), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, holder, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(holder), free(buffer), NULL);
		holder[byte_read] = '\0';
		buffer = ft_join(buffer, holder);
		if (my_strchr(holder, '\n'))
			break ;
	}
	free(holder);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = my_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer [i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = my_calloc(my_strlen(buffer) - i, sizeof(char));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
