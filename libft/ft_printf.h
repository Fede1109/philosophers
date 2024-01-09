/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <edu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:57:04 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/29 11:51:44 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_char(int c);
int		ft_dig(long nb, int base, int n);
int		ft_print_format(char c, va_list args);
int		ft_printf(char const *format, ...);
int		ft_ptr(unsigned long ptr);
int		ft_str(char *str);

#endif
