/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_hex_oct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:36:49 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:12:27 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initbeforeprint(t_print *printf, t_ibf *i)
{
	i->saveitoa = printf->itoa;
	i->y = 0;
	i->i = ft_strlen(printf->itoa);
	i->f = ft_read_flag(printf->flags, printf);
	check_precision(printf, i->i);
}

void	ft_print_hexoctal(t_print *printf, char c)
{
	t_ibf i;

	initbeforeprint(printf, &i);
	if (i.f == 20 && (c == 'x' || c == 'X'))
		print_flag_hash_x(printf, i.i, i.y, c);
	else if (i.f == 20 && (c == 'o' || c == 'O'))
		print_flag_hash_o(printf, i.i, i.y, c);
	else if (i.f == 7 || i.f == 12)
		print_flag_minus(printf, i.i, i.y);
	else if (i.f == 5)
		print_flag_zero(printf, i.i, i.y);
	else if ((i.f == 27 || i.f == 32) && (c == 'x' || c == 'X'))
		print_flags_minushash_x(printf, i.i, i.y, c);
	else if ((i.f == 27 || i.f == 32) && (c == 'o' || c == 'O'))
		print_flags_minushash_o(printf, i.i, i.y, c);
	else if (i.f == 25 && (c == 'x' || c == 'X'))
		print_flag_zerohash_x(printf, i.i, i.y, c);
	else if (i.f == 25 && (c == 'o' || c == 'O'))
		print_flag_zerohash_o(printf, i.i, i.y);
	else if (i.f == 0)
		print_flag_no(printf, i.i, i.y);
	ft_strdel(&i.saveitoa);
}

void	print_hex_oct(t_print *printf, va_list **ap, char c)
{
	int					base;
	unsigned char		x;
	unsigned short int	s;

	base = ((c == 'o' || c == 'O') ? 8 : 16);
	if (printf->length == 1)
	{
		x = va_arg(**ap, unsigned int);
		printf->itoa = ft_itoa_base(x, base, c);
	}
	else if (printf->length == 2)
	{
		s = va_arg(**ap, unsigned int);
		printf->itoa = ft_itoa_base(s, base, c);
	}
	else if (printf->length == 3)
		printf->itoa = ft_itoa_base_ull(va_arg(**ap, unsigned long long int), \
																base, c);
	else if (printf->length == 4)
		printf->itoa = ft_itoa_base_ul(va_arg(**ap, unsigned long int), \
																base, c);
	else
		printf->itoa = ft_itoa_base(va_arg(**ap, unsigned int), base, c);
	ft_print_hexoctal(printf, c);
}
