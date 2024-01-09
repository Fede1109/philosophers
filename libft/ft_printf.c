/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:03:50 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/28 16:03:58 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		check;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
			i += ft_print_format(*++format, args);
		else
		{
			check = write(1, format, 1);
			if (check != -1)
				i += check;
		}
		++format;
		if (i < 0 || check == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (i);
}
