/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:00:26 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/04 14:44:04 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_print_str(t_print *printf)
{
	t_ibf	i;
	int		a;

	a = 0;
	if (printf->itoa == NULL)
	{
		printf->itoa = ft_strdup("(null)");
		a = 1;
	}
	i.i = ft_strlen(printf->itoa);
	i.f = ft_read_flag(printf->flags, printf);
	i.y = 0;
	check_precision(printf, i.i);
	if (i.f == 7 || i.f == 12 || i.f == 53)
		print_str_minus(printf, i.i, i.y);
	else if (i.f == 5)
		print_flag_zero(printf, i.i, i.y);
	else if (i.f == 45)
		print_flag_zero(printf, i.i, i.y);
	else
		print_str_no(printf, i.i, i.y);
	a > 0 ? ft_strdel(&printf->itoa) : 1;
}

void		ft_print_pointer(t_print *printf)
{
	int		i;
	int		y;
	int		f;
	char	*savepointer;

	savepointer = printf->pointer;
	i = ft_strlen(printf->pointer);
	f = ft_read_flag(printf->flags, printf);
	y = 0;
	if (f == 7)
		print_point_minus(printf, i, y);
	else
		print_point_noflag(printf, i, y);
	ft_strdel(&savepointer);
}

void		ft_print_char(t_print *printf)
{
	int		i;
	int		y;
	int		f;

	i = 1;
	y = 0;
	f = ft_read_flag(printf->flags, printf);
	if (f == 7)
		print_char_minus(printf, i, y);
	else
		print_char_noflag(printf, i, y);
}

void		s_print_csp(t_print *printf, va_list **ap, char c)
{
	if (c == 's' || c == 'S')
	{
		printf->itoa = va_arg(**ap, char*);
		ft_print_str(printf);
	}
	else if (c == 'c' || c == 'C')
	{
		printf->ch = va_arg(**ap, int);
		ft_print_char(printf);
	}
	else if (c == 'p' || c == 'P')
	{
		printf->p = va_arg(**ap, unsigned long);
		printf->pointer = ft_pointer_itoa(printf->p);
		ft_print_pointer(printf);
	}
}
