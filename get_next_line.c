/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:53 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/22 06:08:32 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	ptr = (char *)s;
	while (len-- >= 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

static char	*append(char *line, char *buffer, int len)
{
	char			*temp;
	unsigned short	len_line;
	unsigned short	len_buff;

	if (line == NULL)
		return (ft_substr(buffer, 0, len));
	len_buff = ft_strlen(buffer);
	len_line = ft_strlen(line);
	temp = ft_calloc(len_buff + len_line + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_memmove(temp, line, len_line);
	ft_memmove(temp + len_line, buffer, len);
	free(line);
	line = NULL;
	return (temp);
}

static int	check_errors(int fd, char *buffer)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (1);
	if (read(fd, NULL, 0) < 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*end;
	int			len;

	if (check_errors(fd, buffer))
		return (NULL);
	line = NULL;
	if (!buffer[0])
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (NULL);
	end = ft_strchr(buffer, '\n');
	while (end == NULL)
	{
		line = append(line, buffer, ft_strlen(buffer));
		ft_bzero(buffer, BUFFER_SIZE);
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (line);
		end = ft_strchr(buffer, '\n');
	}
	len = ++end - buffer;
	line = append(line, buffer, len);
	ft_memmove(buffer, buffer + len, BUFFER_SIZE - len);
	ft_bzero(buffer + (BUFFER_SIZE - len), len);
	return (line);
}
