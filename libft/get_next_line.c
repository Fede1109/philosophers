/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:42:05 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 12:27:15 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_write_in_aux(int fd, char *aux)
{
	char	*buffer;
	int		check;

	check = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(aux, '\n')) && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			free(aux);
			return (NULL);
		}
		buffer[check] = '\0';
		aux = ft_strjoin_2(aux, buffer);
	}
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	char			*line;	
	static char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = ft_write_in_aux(fd, aux);
	if (!aux)
		return (NULL);
	line = ft_extract_line(aux);
	aux = ft_new_static(aux);
	return (line);
}
