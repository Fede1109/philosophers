/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:51:13 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/14 15:51:15 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*aux;

	aux = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			aux = (char *)&s[i];
		i++;
	}
	if (aux)
		return (aux);
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	else
		return (NULL);
}
