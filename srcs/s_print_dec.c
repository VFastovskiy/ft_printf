/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:08:31 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/03 15:08:34 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					dibf(t_print *printf, t_ibf *i)
{
	i->saveitoa = printf->itoa;
	i->i = ft_strlen(printf->itoa);
	i->f = ft_read_flag(printf->flags, printf);
	i->y = 0;
	check_precision(printf, i->i);
}

void					ft_print_sn_add(t_print *printf, t_ibf *i)
{
	if (i->f == 47 || i->f == 52 || i->f == 48 || i->f == 53)
		print_flag_minplu(printf, i->i, i->y);
	if (i->f == 8 || i->f == 13)
		print_flag_minspace(printf, i->i, i->y);
	if (i->f == 45 || i->f == 46)
		print_flag_zero_plus(printf, i->i, i->y);
	if (i->f == 6)
		print_flag_space_zero(printf, i->i, i->y);
	if (i->f == 0)
		print_flag_no(printf, i->i, i->y);
}

void					ft_print_signed_number(t_print *printf)
{
	t_ibf				i;

	dibf(printf, &i);
	(printf->fl = (ft_atoi(printf->itoa) > 0) ? 1 : 0);
	if (i.f == 7 || i.f == 12)
		print_flag_minus(printf, i.i, i.y);
	if ((i.f == 40 || i.f == 41) && printf->uns == 0)
		print_flag_plus(printf, i.i, i.y);
	if ((i.f == 40 || i.f == 41) && printf->uns == 1)
		print_flag_no(printf, i.i, i.y);
	if (i.f == 1 && printf->uns == 0)
		print_flag_space(printf, i.i, i.y);
	if (i.f == 1 && printf->uns == 1)
		print_flag_no(printf, i.i, i.y);
	if (i.f == 5)
		print_flag_zero(printf, i.i, i.y);
	ft_print_sn_add(printf, &i);
	ft_strdel(&i.saveitoa);
}

void					print_dec(t_print *printf, va_list **ap, char c)
{
	signed char			x;
	short int			s;

	printf->uns = 0;
	if (printf->length == 1 && c != 'D')
	{
		x = va_arg(**ap, int);
		printf->itoa = ft_itoa(x);
	}
	else if (printf->length == 2 && c != 'D')
	{
		s = va_arg(**ap, int);
		printf->itoa = ft_itoa(s);
	}
	else if (printf->length == 3 || c == 'D')
		printf->itoa = ft_itoa_lli(va_arg(**ap, long long int));
	else if (printf->length == 4 || c == 'D')
		printf->itoa = ft_itoa_li(va_arg(**ap, long int));
	else
		printf->itoa = ft_itoa(va_arg(**ap, int));
	ft_print_signed_number(printf);
}

void					print_udec(t_print *printf, va_list **ap, char c)
{
	unsigned char		x;
	unsigned short int	s;

	printf->uns = 1;
	if (printf->length == 1 && c != 'U')
	{
		x = va_arg(**ap, unsigned int);
		printf->itoa = ft_uitoa(x);
	}
	else if (printf->length == 2 && c != 'U')
	{
		s = va_arg(**ap, int);
		printf->itoa = ft_uitoa(s);
	}
	else if (printf->length == 3 || c == 'U')
		printf->itoa = ft_uitoa_ull(va_arg(**ap, unsigned long long int));
	else if (printf->length == 4 || c == 'U')
		printf->itoa = ft_uitoa_ul(va_arg(**ap, unsigned long int));
	else
		printf->itoa = ft_uitoa(va_arg(**ap, unsigned int));
	ft_print_signed_number(printf);
}
