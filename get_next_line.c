/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:38:38 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/07 17:51:12 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_add(int fd, char *saved)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(saved);
		return (NULL);
	}
	while (!(ft_strchr(saved, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(saved);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	return (saved);
}

static char	*extract_line(char *saved)
{
	char		*line;
	size_t		line_length;

	if (!saved)
		return (NULL);
	line_length = 0;
	while (saved[line_length] && saved[line_length] != '\n')
		line_length++;
	line_length += (saved[line_length] == '\n');
	line = malloc(line_length + 1);
	if (!line)
	{
		free(saved);
		return (NULL);
	}
	ft_memcpy(line, saved, line_length);
	line[line_length] = '\0';
	return (line);
}

static char	*extract_saved(char *saved)
{
	size_t	lefto_length;
	char	*extracted_saved;
	char	*new_saved;

	lefto_length = 0;
	new_saved = ft_strchr(saved, '\n');
	if (!new_saved || !new_saved[lefto_length + 1])
	{
		free(saved);
		return (NULL);
	}
	while (new_saved[lefto_length + 1])
		lefto_length++;
	extracted_saved = malloc(lefto_length + 1);
	if (!extracted_saved)
	{
		free(saved);
		return (NULL);
	}
	ft_memcpy(extracted_saved, new_saved + 1, lefto_length);
	extracted_saved[lefto_length] = '\0';
	free(saved);
	return (extracted_saved);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_add(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	if (!line)
	{
		saved = NULL;
		return (NULL);
	}
	saved = extract_saved(saved);
	return (line);
}
