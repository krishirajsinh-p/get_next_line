/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:49 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 01:42:32 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = 0;
}

void *ft_calloc(size_t count, size_t size)
{
	// Check for potential overflow
	if (count * size > SIZE_MAX)
		return (NULL);

	// Allocate memory
	void *ptr = malloc(count * size);
	if (!ptr)
		return NULL;

	// Zero-initialize the allocated memory
	ft_bzero(ptr, count * size);
	return ptr;
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return NULL; // Return NULL if dst or src pointer are pointing to NULL

	unsigned char *ptr_dst = (unsigned char *)dst;
	const unsigned char *ptr_src = (const unsigned char *)src;

	// Copy memory from src to dst
	for (size_t i = 0; i < n; i++)
		ptr_dst[i] = ptr_src[i];

	return dst;
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *d = (char *)dst;
	const char *s = (const char *)src;

	// Check if src and dst regions overlap
	if (src < dst)
	{
		// Move from the end to the beginning to avoid overwriting data
		d += len - 1;
		s += len - 1;
		while (len--)
			*(d--) = *(s--);
	}
	else
	{
		// Call ft_memcpy if src and dst do not overlap
		ft_memcpy(dst, src, len);
	}

	return dst;
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	if (!s)
		return NULL; // Handle the case where s is NULL

	size_t s_len = ft_strlen(s);

	// Adjust start and len if start exceeds string length
	if (start >= s_len)
	{
		start = s_len;
		len = 0;
	}
	else if (len > s_len - start)
	{
		len = s_len - start;
	}

	// Allocate memory for the substring
	char *ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return NULL;

	// Copy the substring from s to ptr
	ft_memcpy(ptr, s + start, len);

	return ptr;
}

size_t ft_strlen(const char *s)
{
	size_t i = 0;

	// Iterate through the string until reaching the null terminator
	while (s[i] != '\0')
		i++;

	return i;
}

char *ft_strchr(const char *s, int c)
{
	char *ptr = (char *)s;

	// Loop through the string until the null terminator is reached
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return ptr; // Return a pointer to the first occurrence of c
		ptr++;
	}

	// Check if c is the null terminator
	if ((char)c == '\0')
		return ptr; // Return a pointer to the null terminator if c is found

	// Return NULL if c is not found in the string
	return NULL;
}
