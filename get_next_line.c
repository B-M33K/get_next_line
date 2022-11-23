/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:15:58 by obahi             #+#    #+#             */
/*   Updated: 2022/11/23 18:16:33 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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

static char	*ft_keep_reading(char **line, char *buffer, char **remain)
{
	char	*n;

	n = 0;
	n = ft_strchr(buffer, '\n');
	if (n)
	{
		*line = ft_strjoin_c(*line, buffer, '\n');
		if (*(n + 1))
			*remain = ft_strdup(n + 1);
		else
			*remain = 0;
	}
	else
		*line = ft_strjoin_c(*line, buffer, '\n');
	return (n);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		buffer[BUFFER_SIZE + 1];
	int			count;
	char		*line;
	char		*n;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		ft_free(&remain);
		return (0);
	}
	n = ft_check_remain(&line, &remain);
	while (n == 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count > 0)
		{
			buffer[count] = 0;
			n = ft_keep_reading(&line, buffer, &remain);
		}
		else
			return (ft_free(&remain), line);
	}
	return (line);
}
