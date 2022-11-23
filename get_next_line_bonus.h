/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:15:26 by obahi             #+#    #+#             */
/*   Updated: 2022/11/23 18:21:29 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
void	ft_free(char **p);
char	*ft_strdup(char *src);
int		ft_strlen_c(char *str, char c);
char	*ft_strjoin_c(char *s1, char *s2, char c);
char	*ft_strchr(char *str, char c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#endif