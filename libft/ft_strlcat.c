/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:03:18 by ecortes-          #+#    #+#             */
/*   Updated: 2023/07/11 19:03:20 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	i = 0;
	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	if (size <= lend)
		return (size + lens);
	while (src[i] != '\0' && i < (size - lend - 1))
	{
		dest[lend + i] = src[i];
		i++;
	}
	dest[lend + i] = '\0';
	return (lend + lens);
}
