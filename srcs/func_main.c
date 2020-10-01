/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:57:54 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 15:32:54 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

void		main_init(t_print *printf)
{
	printf->width = 0;
	printf->count = 0;
	printf->prec = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_print			printf;
	char			*c;

	va_start(ap, format);
	main_init(&printf);
	c = (char *)format;
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			analyze_sum(&printf, &ap, &c);
			if (*c == '$')
				break ;
			analyze_spec(&printf, &ap, &c);
			ft_strdel(&printf.flags);
		}
		else
			ft_putchar_pf(*c, &printf);
		if (*c != '\0')
			c++;
	}
	va_end(ap);
	return (printf.count);
}
