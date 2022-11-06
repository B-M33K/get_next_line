/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:38:19 by obahi             #+#    #+#             */
/*   Updated: 2022/11/06 15:43:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
int		ft_strlen_c(char *str, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_c(char *s1, char *s2, char c);
char	*ft_strchr(char *str, char c);

#endif