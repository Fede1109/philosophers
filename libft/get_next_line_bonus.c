/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:45:38 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 12:27:34 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_write_in_aux(int fd, char *aux)
{
	char	*buffer;
	int		check;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	check = 1;
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
	static char		*aux[7000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux[fd] = ft_write_in_aux(fd, aux[fd]);
	if (!aux[fd])
		return (NULL);
	line = ft_extract_line(aux[fd]);
	aux[fd] = ft_new_static(aux[fd]);
	return (line);
}
