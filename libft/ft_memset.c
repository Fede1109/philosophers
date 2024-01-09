/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:22:35 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/11 17:22:40 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	v;

	str = (char *)b;
	v = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = v;
		i++;
	}
	return ((void *)(str));
}
