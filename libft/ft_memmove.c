/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:14:43 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/20 15:14:45 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *b, const void *c, size_t len)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = b;
	src = (unsigned char *)c;
	if (src > dest)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (src < dest)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
	return (dest);
}
