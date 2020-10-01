/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_inf_nan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:12:42 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/03 15:14:31 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_inf_add(t_print *printf, t_ibf *i)
{
	if (i->f == 20)
		print_flag_no(printf, i->i, i->y);
	if (i->f == 27)
		print_flag_minus(printf, i->i, i->y);
	if (i->f == 67 || i->f == 72)
		print_flag_minplu(printf, i->i, i->y);
	if (i->f == 6)
		print_flag_space(printf, i->i, i->y);
	if (i->f == 28 || i->f == 33)
		print_flag_minspace(printf, i->i, i->y);
	else if (i->f == 0)
		print_flag_no(printf, i->i, i->y);
}

void	ft_print_nan_add(t_print *printf, t_ibf *i)
{
	if (i->f == 20)
		print_flag_no(printf, i->i, i->y);
	if (i->f == 27)
		print_flag_minus(printf, i->i, i->y);
	if (i->f == 67 || i->f == 72)
		print_flag_minus(printf, i->i, i->y);
	if (i->f == 6)
		print_flag_no(printf, i->i, i->y);
	if (i->f == 28 || i->f == 33)
		print_flag_minus(printf, i->i, i->y);
	else if (i->f == 0)
		print_flag_no(printf, i->i, i->y);
}

void	ft_print_nan(t_print *printf)
{
	t_ibf i;

	fibp(printf, 1, &i);
	if (i.f == 7 || i.f == 12)
		print_flag_minus(printf, i.i, i.y);
	if (i.f == 40 || i.f == 41)
		print_flag_no(printf, i.i, i.y);
	if (i.f == 1)
		print_flag_no(printf, i.i, i.y);
	if (i.f == 5)
		print_flag_no(printf, i.i, i.y);
	if (i.f == 47 || i.f == 52)
		print_flag_minus(printf, i.i, i.y);
	if (i.f == 8 || i.f == 13)
		print_flag_minus(printf, i.i, i.y);
	if (i.f == 45)
		print_flag_no(printf, i.i, i.y);
	ft_print_nan_add(printf, &i);
	ft_strdel(&i.saveitoa);
}

void	ft_print_inf(t_print *printf)
{
	t_ibf i;

	fibp(printf, 1, &i);
	if (i.f == 7 || i.f == 12)
		print_flag_minus(printf, i.i, i.y);
	if (i.f == 40 || i.f == 41)
		print_flag_plus(printf, i.i, i.y);
	if (i.f == 1)
		print_flag_space(printf, i.i, i.y);
	if (i.f == 5)
		print_flag_no(printf, i.i, i.y);
	if (i.f == 47 || i.f == 52)
		print_flag_minplu(printf, i.i, i.y);
	if (i.f == 8 || i.f == 13)
		print_flag_minspace(printf, i.i, i.y);
	if (i.f == 45)
		print_flag_plus(printf, i.i, i.y);
	ft_print_inf_add(printf, &i);
	ft_strdel(&i.saveitoa);
}
