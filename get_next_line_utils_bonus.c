/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:15:37 by obahi             #+#    #+#             */
/*   Updated: 2022/11/23 18:15:40 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = 0;
	}
}

int	ft_strlen_c(char *str, char c)
{
	char	*ptr;

	ptr = str;
	while (*ptr && *ptr != c)
		ptr++;
	return (ptr - str);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = 0;
	dup = (char *)malloc(ft_strlen_c(src, 0) + 1);
	if (dup)
	{
		while (*(src + i))
		{
			*(dup + i) = *(src + i);
			i++;
		}
		*(dup + i) = '\0';
	}
	return (dup);
}

char	*ft_strjoin_c(char *s1, char *s2, char c)
{
	char	*join;
	char	*tmp;
	int		size;
	char	*tt;

	if (!s1)
		s1 = ft_strdup("");
	tt = s1;
	size = ft_strlen_c(s1, 0) + ft_strlen_c(s2, c) + 1;
	if (ft_strchr(s2, c))
		size++;
	join = malloc(size);
	if (join)
	{
		tmp = join;
		while (*s1)
			*tmp++ = *s1++;
		while (*s2 && *s2 != c)
			*tmp++ = *s2++;
		if (ft_strchr(s2, c))
			*tmp++ = '\n';
		*tmp = '\0';
	}
	free(tt);
	return (join);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (str + i);
		i++;
	}
	return (0);
}
