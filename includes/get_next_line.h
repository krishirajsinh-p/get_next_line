/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2024/04/08 12:59:27 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#define FD_SETSIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Reads from a file descriptor and returns each line from the input.
 *
 * This function reads from the file descriptor `fd` and returns each line from the input
 * until the end of file is reached. It uses a static buffer to store partial lines between
 * successive calls. It supports reading from multiple file descriptors concurrently.
 *
 * @param fd The file descriptor from which to read.
 *
 * @return Upon successful completion, the function returns a pointer to the next line read
 * from the file descriptor. If the end of file is reached, NULL is returned. If any error
 * occurs during reading, NULL is returned.
 */
char *get_next_line(int fd);

/**
 * @brief Sets the first n bytes of the memory area pointed to by s to zero.
 *
 * @param s The pointer to the memory area.
 * @param n The number of bytes to be zeroed.
 */
void ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of count elements of size bytes each and initializes all bits to zero.
 *
 * @param count The number of elements to allocate.
 * @param size The size of each element.
 * @return A pointer to the allocated memory block, or NULL if the allocation fails.
 */
void *ft_calloc(size_t count, size_t size);

/**
 * @brief Copies n bytes from memory area src to memory area dst.
 *
 * @param dst The pointer to the destination memory area.
 * @param src The pointer to the source memory area.
 * @param n The number of bytes to be copied.
 * @return A pointer to the destination memory area.
 */
void *ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies len bytes from memory area src to memory area dst, handling overlapping memory blocks.
 *
 * @param dst The pointer to the destination memory area.
 * @param src The pointer to the source memory area.
 * @param len The number of bytes to be copied.
 * @return A pointer to the destination memory area.
 */
void *ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Calculates the length of the given string.
 *
 * @param s The string to be measured.
 * @return The length of the string.
 */
size_t ft_strlen(const char *s);

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * @param s The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the located character, or NULL if the character does not appear in the string.
 */
char *ft_strchr(const char *s, int c);

/**
 * @brief Allocates and returns a substring from the string s.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in s.
 * @param len The length of the substring.
 * @return The substring, or NULL if the allocation fails.
 */
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif
