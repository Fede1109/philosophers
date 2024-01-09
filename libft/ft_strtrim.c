/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:59:08 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/12 16:59:10 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	size_t				j;
	char				*arr;

	j = ft_strlen(s1);
	i = 0;
	while (ft_set(s1[i], set) == 1)
	{
		i++;
	}
	while (ft_set(s1[j - 1], set) == 1)
	{
		j--;
	}
	arr = ft_substr(s1, i, j - i);
	return (arr);
}
