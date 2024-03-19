/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2024/03/19 01:45:40 by kpuwar           ###   ########.fr       */
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

char *get_next_line(int fd);

void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t count, size_t size);
size_t ft_strlen(const char *s);
void *ft_memmove(void *dst, const void *src, size_t len);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif
