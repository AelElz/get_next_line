/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:36:45 by ael-azha          #+#    #+#             */
/*   Updated: 2024/12/05 17:16:59 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	my_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

void	*my_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	total_size;

	if (count == 0 || size == 0)
		return (malloc(0));
	total_size = count * size;
	new = malloc(total_size);
	if (!new)
		return (NULL);
	my_bzero(new, total_size);
	return (new);
}

char	*my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len1 = my_strlen(s1);
	len2 = my_strlen(s2);
	new = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ptr = new;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (new);
}
