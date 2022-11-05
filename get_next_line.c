/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:50:54 by obahi             #+#    #+#             */
/*   Updated: 2022/11/05 12:08:33 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_check_remain(char **line, char *remain)
{
	char	*new_line;
	
	new_line = 0;
	if (remain)
	{
		new_line = ft_strchr(remain, '\n');
		if (new_line)
		{
			*line = strndup(remain, ft_strlen_c(remain, '\n') + 1);
			// *new_line = '\0';
			// *line = ft_strdup_c(remain, '\n');
			// ft_strcpy(remain, (new_line + 1));
			// *line = strdup(remain);
			// *line = ft_strjoin_c(*line, "\n", '\n');
			strcpy(remain, new_line + 1);
		}
		else
		{
			// *line = ft_strdup_c(remain, 0);
			*line = strdup(remain);
			ft_bzero(remain);
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	char		*new_line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = ft_check_remain(&line, remain);
	while (!new_line)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count)
		{
			buff[count] = '\0';
			new_line = ft_strchr(buff, '\n');
			if (new_line)
			{
				if(remain)
					free(remain);
				// remain = ft_strdup_c((new_line + 1), 0);
				remain = strdup(new_line + 1);
			}
			line = ft_strjoin_c(line, buff, '\n');
		}
		else
			break ;
	}
	if (*line)
	{
		return (line);
	}
	else
	{
		free(line);
		return (0);
	}
}

// int main(void)
// {
// 	int fd = open("txt", O_RDONLY);
// 	char *l;
// 	while((l = get_next_line(fd)))
// 	{
// 		printf("~~%s~~",l);
// 	}
// }
