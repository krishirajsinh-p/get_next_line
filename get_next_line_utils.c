/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:49 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/22 01:38:21 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (src < dst)
	{
		d = dst + len - 1;
		s = src + len - 1;
		while (len-- > 0)
			*(d--) = *(s--);
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	len_str;

	len_str = ft_strlen(s);
	if (start > len_str)
		return (ft_calloc(0, 0));
	if (len > len_str - start)
		len = len_str - start;
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	return ((char *)ft_memmove(ptr, (s + start), len));
}
