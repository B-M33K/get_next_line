/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meek <meek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:50:54 by obahi             #+#    #+#             */
/*   Updated: 2022/11/09 19:35:48 by meek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static void	ft_free(char **p)
{
	free(*p);
	*p = 0;
}

static char	*ft_check_remain(char **line, char **remain)
{
	char	*n;
	char	*tmp;

	n = 0;
	if (*remain)
	{
		n = ft_strchr(*remain, '\n');
		if (n)
		{
			*line = ft_strjoin_c(*line, *remain, '\n');
			tmp = *remain;
			if (*(n + 1))
				*remain = ft_strdup(n + 1);
			else
				*remain = 0;
			ft_free(&tmp);
		}
		else
		{
			*line = ft_strjoin_c(*line, *remain, 0);
			ft_free(remain);
		}
	}
	return (n);
}

static char	*ft_keep_reading(char **line, char **buffer, char **remain)
{
	char	*n;

	n = 0;
	n = ft_strchr(*buffer, '\n');
	if (n)
	{
		*line = ft_strjoin_c(*line, *buffer, '\n');
		if (*(n + 1))
			*remain = ft_strdup(n + 1);
		else
			*remain = 0;
		ft_free(buffer);
	}
	else
	{
		*line = ft_strjoin_c(*line, *buffer, '\n');
		ft_free(buffer);
	}
	return (n);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*buffer;
	int			count;
	char		*line;
	char		*n;

	line = 0;
	buffer = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n = ft_check_remain(&line, &remain);
	while (n == 0)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (0);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count > 0)
		{
			n = ft_keep_reading(&line, &buffer, &remain);
		}
		else
			return (ft_free(&buffer), line);
	}
	return (line);
}
