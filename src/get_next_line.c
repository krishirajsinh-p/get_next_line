/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:53 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 12:59:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/**
 * @brief Appends a buffer to a line or creates a new line if none exists.
 *
 * This function appends the buffer `buffer` of length `len` to the existing line `line`.
 * If `line` is NULL, it creates a new line by copying `len` characters from `buffer`.
 * The resulting string is returned.
 *
 * @param line The existing line to which the buffer will be appended. If NULL, a new line is created.
 * @param buffer The buffer to be appended to the line.
 * @param len The length of the buffer to be appended.
 *
 * @return Upon successful completion, the function returns the resulting string after appending.
 * If memory allocation fails, NULL is returned.
 */
static char *append(char *line, char *buffer, int len)
{
	char *new_line;
	unsigned short len_line;
	unsigned short len_buff;

	if (line == NULL)
		return (ft_substr(buffer, 0, len));
	len_buff = ft_strlen(buffer);
	len_line = ft_strlen(line);
	new_line = ft_calloc(len_buff + len_line + 1, sizeof(char));
	if (new_line == NULL)
		return (NULL);
	ft_memmove(new_line, line, len_line);
	ft_memmove(new_line + len_line, buffer, len);
	free(line);
	return (new_line);
}

/**
 * @brief Checks for errors related to file descriptor and buffer size.
 *
 * This function checks if the file descriptor `fd` is valid and if the `BUFFER_SIZE`
 * is greater than zero. It also checks if the file descriptor is readable.
 * If any error is encountered, it clears the buffer and returns 1.
 *
 * @param fd The file descriptor to check for validity.
 * @param buffer The buffer associated with the file descriptor.
 *
 * @return If any error is encountered, 1 is returned. Otherwise, 0 is returned.
 */
static int check_errors(int fd, char *buffer)
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

char *get_next_line(int fd)
{
	static char buffer[FD_SETSIZE][(BUFFER_SIZE > 0) * (BUFFER_SIZE + 1)];
	char *line;
	char *end;
	int len;

	if (check_errors(fd, buffer[fd]))
		return (NULL);
	line = NULL;
	if (!buffer[fd][0])
		if (read(fd, buffer[fd], BUFFER_SIZE) == 0)
			return (NULL);
	end = ft_strchr(buffer[fd], '\n');
	while (end == NULL)
	{
		line = append(line, buffer[fd], ft_strlen(buffer[fd]));
		ft_bzero(buffer[fd], BUFFER_SIZE);
		if (read(fd, buffer[fd], BUFFER_SIZE) == 0)
			return (line);
		end = ft_strchr(buffer[fd], '\n');
	}
	len = ++end - buffer[fd];
	line = append(line, buffer[fd], len);
	ft_memmove(buffer[fd], buffer[fd] + len, BUFFER_SIZE - len);
	ft_bzero(buffer[fd] + (BUFFER_SIZE - len), len);
	return (line);
}

/*
//for testing uncomment this block and run with:
//$> gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10 && ./a.out
#include <stdio.h>
int	main(void)
{
	FILE	*file1;
	FILE	*file2;
	char	*ptr1;
	char	*ptr2;
	int		i = 1;

	file1 = fopen("test1.txt", "r");
	file2 = fopen("test2.txt", "r");
	while ((ptr1 = get_next_line(fileno(file1)))
	&& (ptr2 = get_next_line(fileno(file2))))
	{
		printf("test1.txt [%i]\t%s", i, ptr1);
		printf("test2.txt [%i]\t%s", i++, ptr2);
		free(ptr1);
		free(ptr2);
	}
	fclose(file1);
	fclose(file2);
	return (0);
}
*/
