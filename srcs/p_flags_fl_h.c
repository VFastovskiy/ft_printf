/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_fl_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:46:54 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:07:59 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flag_float_hash_add2(t_print *printf)
{
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		printf->prec == 0 ? ft_putchar_pf('.', printf) : 1;
	}
	else
	{
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		printf->prec == 0 ? ft_putchar_pf('.', printf) : 1;
	}
}

void	print_flag_float_hash_add(t_print *printf, int i, int y)
{
	printf->width -= i + printf->precision;
	while (y++ < printf->width)
		ft_putchar_pf(' ', printf);
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		printf->prec == 0 ? ft_putchar_pf('.', printf) : 1;
	}
	else
	{
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		printf->prec == 0 ? ft_putchar_pf('.', printf) : 1;
	}
}

void	print_flag_float_hash(t_print *printf, int i, int y)
{
	int		f;

	f = 0;
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	else if (printf->width > i + printf->precision)
		print_flag_float_hash_add(printf, i, y);
	else if (printf->width <= i + printf->precision)
		print_flag_float_hash_add2(printf);
}
