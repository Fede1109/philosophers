/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:15:12 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/12 16:15:14 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	if (*to_find == '\0')
		return ((char *)(str));
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			result = (char *)&str[i];
			while (to_find[j] != '\0' && str[i + j] == to_find[j])
			{
				j++;
			}
			if (to_find[j] == '\0' && i + ft_strlen(to_find) <= n)
				return (result);
		}
		i++;
	}
	return (NULL);
}
