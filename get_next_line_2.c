#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>
#include<unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char			*p;
	unsigned int	i;

	if (!s || !n)
		return ;
	p = (char *)s;
	i = 0;
	while (i < n)
	{
		*(p + i) = 0;
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int	i;
	char			*dup;
	unsigned int	size;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (s_len <= n)
		size = s_len + 1;
	else
		size = n + 1;
	dup = (char *)malloc(size);
	if (dup)
	{
		while (i < size)
		{
			*(dup + i) = *(s + i);
			i++;
		}
		*(dup + i) = 0;
	}
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
	}
	return (src_len);
}

char	*ft_strjoin_c(char *s1, char *s2, int c)
{
	unsigned int	i;
	unsigned int	j;
	int				size;
	char			*join;

	if (!s1)
		s1 = ft_strndup("", 0);
	if (!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (c)
		size++;
	i = 0;
	j = 0;
	join = (char *)malloc(size);
	if (join)
	{
		while (*(s1 + i))
		{
			*(join + i) = *(s1 + i);
			i++;
		}
		while (*(s2 + j))
		{
			*(join + i) = *(s1 + j);
			j++;
			i++;
		}
		if (c)
		{
			*(join + i) = c;
			i++;
		}
		*(join + i) = 0;
	}
	free(s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	remain[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*n;
	int			count;

	// ft_bzero(remain, BUFFER_SIZE + 1);
	line = 0;
	if (fd > 0 && BUFFER_SIZE > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (*remain)
		{
			n = ft_strchr(remain, 10);
			if (n)
			{
				*n = 0;
				line = ft_strndup(remain, n - remain);
				if (*(n + 1))
					ft_strlcpy(remain, n + 1, ft_strlen(n + 1));
			}
			else
			{
				line = ft_strndup(remain, ft_strlen(remain));
				ft_bzero(remain, ft_strlen(remain));
			}
		}
		else
		{
			while (!n)
			{
				count = read(fd, buffer, BUFFER_SIZE);
				buffer[count] = 0;
				n = ft_strchr(buffer, 10);
				if (n)
				{
					*n = 0;
					if (*(n + 1))
						ft_strlcpy(remain, n + 1, ft_strlen(n + 1));
					line = ft_strjoin_c(line, buffer, 10);
				}
				else
				{
					line = ft_strjoin_c(line, buffer, 0);
				}
			}
		}
	}
	return (line);
}

int main(void)
{
	int fd;
	fd = open("txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	return (0);
}