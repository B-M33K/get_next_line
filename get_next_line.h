/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:51:35 by obahi             #+#    #+#             */
/*   Updated: 2022/11/04 22:14:08 by obahi            ###   ########.fr       */
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

// #define BUFFER_SIZE 5

char	*get_next_line(int fd);
int		ft_strlen_c(char *str, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup_c(char *str, char c);
int		ft_strchr_c(char *str, char c);
char	*ft_strjoin_c(char *s1, char *s2, char c);
void	ft_bzero(char *s);
char	*ft_strchr(char *str, char c);
void	ft_strcpy(char *s, char *t);

#endif