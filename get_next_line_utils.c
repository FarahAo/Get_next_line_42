/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:34:04 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/05 16:16:20 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	length_s;
	size_t	i;

	i = 0;
	length_s = ft_strlen(s);
	copy = malloc(length_s + 1);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
char	*ft_strjoin(char const *saved, char const *buffer)
{
	char	*new_saved;
	size_t		length;
	size_t		j;
	size_t		i;
	
	if (!saved)
	{
		new_saved = ft_strdup(buffer);
		return (new_saved);
	}
	length = ft_strlen(saved) + ft_strlen(buffer);
	new_saved = malloc(length + 1);
	if (!new_saved)
		return (NULL);
	ft_memcpy(new_saved, saved, ft_strlen(saved));
	j = ft_strlen(saved);
	i = 0;
	while (buffer[i])
		new_saved[j + i] = buffer[i++];
	new_saved[j + i] = '\0';
	return (new_saved);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (NULL);
}


