/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:48:15 by ecortes-          #+#    #+#             */
/*   Updated: 2023/12/04 12:26:32 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1 || !s2)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
		while (s2[++j] != '\0')
			str[i + j] = s2[j];
		str[i + j] = '\0';
	}
	free(s1);
	return (str);
}

char	*ft_extract_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		ret[i] = str[i];
	if (str[i] == '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_new_static(char *aux)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (!aux[i])
	{
		free(aux);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(aux) - i + 1));
	if (!ret)
	{
		free(aux);
		return (NULL);
	}
	i++;
	j = 0;
	while (aux[i] != '\0')
		ret[j++] = aux[i++];
	ret[j] = '\0';
	free(aux);
	return (ret);
}
