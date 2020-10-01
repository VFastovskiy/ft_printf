/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_analyze_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:32:25 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 12:12:57 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	analyze_spec(t_print *printf, va_list *ap, char **c)
{
	printf->fl = 0;
	if (**c == 'd' || **c == 'i' || **c == 'D' || **c == 'I')
		print_dec(printf, &ap, **c);
	else if (**c == 'u' || **c == 'U')
		print_udec(printf, &ap, **c);
	else if (**c == 'o' || **c == 'O' || **c == 'x' || **c == 'X')
		print_hex_oct(printf, &ap, **c);
	else if (**c == 's' || **c == 'S' || **c == 'p' || **c == 'P' \
										|| **c == 'c' || **c == 'C')
		s_print_csp(printf, &ap, **c);
	else if (**c == 'f' || **c == 'F')
		s_print_float(printf, &ap);
	else if (**c == '%')
	{
		printf->ch = '%';
		ft_print_perc(printf);
	}
	else if (ft_isalpha(**c) == 1)
	{
		printf->ch = **c;
		print_char_noflag(printf, 1, 0);
		return ;
	}
	else
		return ;
}
