/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:51:38 by jconde-a          #+#    #+#             */
/*   Updated: 2023/10/24 19:17:48 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>  //Tiene la función Read
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>  // tiene los tipos

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    imprimirCadena(const char *cadena);
char	*ft_readed(int fd, char *readed, char *buffer);
// void    leaks();
#endif

#ifndef  BUFFER_SIZE
# define BUFFER_SIZE 42
#endif