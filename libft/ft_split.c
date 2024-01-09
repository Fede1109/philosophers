/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:48:27 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/15 13:48:28 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_extract_word(char const *s, char c, int *i)
{
	int	start;
	int	end;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	end = *i;
	return (ft_substr(s, start, end - start));
}

static void	ft_free_split(char **str, size_t words)
{
	while (words-- > 0)
	{
		free(str[words]);
		str[words] = NULL;
	}
	free(str);
	str = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		z;

	i = 0;
	z = 0;
	str = ft_calloc(sizeof (char *), (ft_count_words(s, c) + 1));
	while (s[i] && str != NULL)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			str[z] = ft_extract_word(s, c, &i);
			if (str[z] == NULL)
			{
				ft_free_split(str, ft_count_words(s, c));
				return (NULL);
			}
			z++;
		}
		else
			i++;
	}
	if (str != NULL)
		str[z] = NULL;
	return (str);
}
