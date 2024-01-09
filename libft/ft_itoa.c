/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:13:44 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/14 15:13:46 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	int			count;
	long int	i;

	i = n;
	count = 0;
	if (i < 0)
	{
		i = -i;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*ft_check(long int nb, char *str, int i)
{
	if (nb == 0)
		str = ft_calloc(2, sizeof(char));
	else
		str = ft_calloc(i + 1, sizeof(char));
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	str = NULL;
	nb = n;
	i = ft_digit_count(nb);
	str = ft_check(nb, str, i);
	if (!str)
		return (NULL);
	str[i--] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
