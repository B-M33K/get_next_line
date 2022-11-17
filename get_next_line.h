/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:28:18 by obahi             #+#    #+#             */
/*   Updated: 2022/11/17 10:54:11 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
void	ft_free(char **p);
char	*ft_strdup(char *src);
int		ft_strlen_c(char *str, char c);
char	*ft_strjoin_c(char *s1, char *s2, char c);
char	*ft_strchr(char *str, char c);

#endif