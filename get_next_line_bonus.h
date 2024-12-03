/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:43:13 by ael-azha          #+#    #+#             */
/*   Updated: 2024/12/03 17:59:49 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
void	my_bzero(void *s, size_t n);
void	*my_calloc(size_t count, size_t size);
char	*my_strchr(const char *s, int c);
size_t	my_strlen(const char *s);
char	*my_strjoin(char const *s1, char const *s2);

#endif
