/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:38:38 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/05 19:55:52 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_to_buffer(int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

static char	*add_to_saved(char *saved, char *buffer)
{
	char	*new_saved;

	new_saved = ft_strjoin(saved, buffer);
	if (!new_saved)
	{
		free(saved);
		free(buffer);
		return (NULL);
	}
	free(saved);
	free(buffer);
	return (new_saved);
}

static char	*extract_line(char *saved)
{
	char	*line;
	size_t		line_length;

	if (!saved)
		return (NULL);
	line_length = 0;
	while (saved[line_length] != '\n' && saved[line_length])
		line_length++;
	line_length += (saved[line_length] == '\n');
	line = malloc(line_length + 1);
       if (!line)
	       return (NULL);
	ft_memcpy(line, saved, line_length);
	line[line_length] = '\0';
	return (line);
}

static char	*extract_saved(char *saved)
{
	size_t	lefto_length;
	char	*extracted_saved;

	lefto_length = 1;
	saved = ft_strchr(saved, '\n');
	while (saved[lefto_length])
		lefto_length++;
	extracted_saved = malloc(lefto_length);
	if (!extracted_saved)
		return (NULL);
	ft_memcpy(extracted_saved, saved + 1, lefto_length);
	extracted_saved[lefto_length] = '\0';
	return (extracted_saved);
}


char	*get_next_line(int fd)
{
	char	*buffer;
	static	char	*saved;
	char	*extracted_saved;
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = save_to_buffer(fd);
	if (!buffer)
		return (NULL);
	saved = add_to_saved(saved, buffer);
	if (!saved)
		return (NULL);
	if (ft_strchr(saved, '\n'))
		line = extract_line(saved);
	extracted_saved = extract_saved(saved);
	if (!extracted_saved)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	free(saved);
	saved = extracted_saved;
	return (line);
}
