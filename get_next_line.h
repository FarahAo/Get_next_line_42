/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:58:48 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/05 18:46:34 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char    *ft_strdup(const char *s);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_strjoin(char const *saved, char const *buffer);
char    *ft_strchr(const char *str, int c);
char *get_next_line(int fd);
#endif
