/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:43:42 by obahi             #+#    #+#             */
/*   Updated: 2022/11/04 22:29:02 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_c(char *str, char c)
{
	char	*ptr;

	ptr = str;
	while (*ptr && *ptr != c)
		ptr++;
	return (ptr - str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		n;
	char	*tmp;

	ptr = 0;
	n = count * size;
	ptr = malloc(n);
	if (ptr)
	{
		tmp = (char *)ptr;
		while (n--)
			*tmp++ = 0;
	}
	return (ptr);
}

char	*ft_strdup_c(char *str, char c)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	dup = 0;
	size = ft_strlen_c(str, c) + 1;
	if (c == '\n')
		size ++;
	dup = malloc(size);
	if (dup)
	{
		while (*(str + i) && *(str + i) != c)
		{
			*(dup + i) = *(str + i);
			i++;
		}
		if (c == '\n')
		{
			*(dup + i) = '\n';
			i++;
		}
		*(dup + i) = '\0';
	}
	return (dup);
}

int	ft_strchr_c(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin_c(char *s1, char *s2, char c)
{
	char	*join;
	char	*tmp;
	int		size;
	char	*tt;

	tt = s1;
	size = ft_strlen_c(s1, 0) + ft_strlen_c(s2, c) + 1;
	if (ft_strchr_c(s2, c))
		size++;
	join = malloc(size);
	if (join)
	{
		tmp = join;
		while (*s1)
			*tmp++ = *s1++;
		while (*s2 && *s2 != c)
			*tmp++ = *s2++;
		if (ft_strchr_c(s2, c))
			*tmp++ = '\n';
		*tmp = '\0';
	}
	free(tt);
	return (join);
}

void	ft_bzero(char	*s)
{
	while (*s)
	{
		*s = 0;
		s++;
	}
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

void	ft_strcpy(char *s, char *t)
{
	int	i;
	i = 0;
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
	}
}
