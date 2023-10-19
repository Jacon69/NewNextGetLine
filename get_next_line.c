/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:58:56 by jconde-a          #+#    #+#             */
/*   Updated: 2023/10/19 14:33:39 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
char	*readed;
char	*buffer_o;
int		num;

	readed = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readed)
		return (NULL);
	while ((buffer) && !ft_strchr(buffer, '\n'))
	{
		num = read(fd, readed, BUFFER_SIZE);
		if (num < 0)
			buffer = NULL;
		else if (num > 0)
		{
			readed[num] = '\0';
			buffer_o = buffer;
			buffer = ft_strjoin(buffer, readed);
			free(buffer_o);
		}
		else
		{
			imprimirCadena ("RESTO:");
			imprimirCadena (buffer);
			break;
		}
	}

	free(readed);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	size_t	len;
	
	if (!ft_strchr(buffer, '\n'))
		len = ft_strlen(buffer);
	else
	{
		len = (size_t) (ft_strchr(buffer, '\n') - buffer + 1);
	}

	line = (char *) malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	if (!ft_strchr(buffer, '\n') || (len == (ft_strlen(buffer) - 1)))
	{
			line = buffer;
			imprimirCadena ("1linea:");
			imprimirCadena (line);
	}
	else
	{
		line = ft_memcpy(line, buffer, len);
	}
	line[len]='\0';
	return (line);
}

char *ft_rest (char *buffer)
{
	char	*rest;
	size_t	len;

	if (!ft_strchr(buffer, '\n'))
		len = 0;
	else
		len = ft_strlen(buffer) - (ft_strchr(buffer, '\n') - buffer + 1);
	rest = (char *) malloc(sizeof(char) * (len + 1));
	if (!rest)
	{
		free(buffer);
		return (NULL);
	}
	rest = ft_memcpy(rest, &buffer[ft_strlen(buffer) - len], len);
	rest[len] = '\0';
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{  
		if (buffer)
			free(buffer);
		return (NULL);
	}
	if (!buffer)
	{
		buffer = (char *) malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = ft_read(fd, buffer);

	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
			imprimirCadena ("linea:");
			imprimirCadena (line);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
			imprimirCadena ("\n1linea:");
			imprimirCadena (line);
	buffer = ft_rest (buffer);
				imprimirCadena ("\n2linea:");
			imprimirCadena (line);
	if (line[0] == '\0')
	{

		free(buffer);
		//free (line);
		return (NULL);
	}
;
	return (line);
}