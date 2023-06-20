/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrodrig <isrodrig@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:55:02 by isrodrig          #+#    #+#             */
/*   Updated: 2023/03/31 11:03:26 by isrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = reading(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next(buffer);
	return (line);
}

char	*reading(int fd, char *a)
{
	char	*buffer;
	int		cread;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(a));
	buffer[0] = '\0';
	cread = 1;
	while (cread > 0 && !ft_strchr(buffer, '\n'))
	{
		cread = read(fd, buffer, BUFFER_SIZE);
		if (cread == -1)
		{
			free(a);
			free(buffer);
			return (NULL);
		}
		if (cread > 0)
		{
			buffer[cread] = '\0';
			a = ft_strjoin(a, buffer);
		}
	}
	free(buffer);
	return (a);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(sizeof(char) * i + 2);
	else
		line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer [i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
		return (ft_free(buffer));
	line = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!line)
		return (ft_free(buffer));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	line[j] = '\0';
	return (line);
}
