/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_pointer_no_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:29:05 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:32:07 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_point_nowidth(t_print *printf, int i)
{
	ft_putstr_pf("0x", printf);
	if (printf->precision == 0)
		return ;
	if (printf->precision > i)
	{
		printf->precision -= i;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
	}
	ft_putstr_pf(printf->pointer, printf);
}

void	print_point_minus(t_print *printf, int i, int y)
{
	if (printf->width > i + 2)
	{
		printf->width -= i + 2;
		ft_putstr_pf("0x", printf);
		if (printf->precision > i)
		{
			printf->precision -= i;
			while (printf->precision-- > 0)
				ft_putchar_pf('0', printf);
		}
		if (printf->precision != 0)
			ft_putstr_pf(printf->pointer, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (printf->width <= i + 2)
		print_point_nowidth(printf, i);
}

void	print_point_noflag(t_print *printf, int i, int y)
{
	if (printf->width > i + 2)
	{
		(printf->precision == 0) ? i = 0 : 1;
		printf->width -= i + 2;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		ft_putstr_pf("0x", printf);
		if (printf->precision == 0)
			return ;
		if (printf->precision > i)
		{
			printf->precision -= i;
			while (printf->precision-- > 0)
				ft_putchar_pf('0', printf);
		}
		ft_putstr_pf(printf->pointer, printf);
	}
	else if (printf->width <= i + 2)
		print_point_nowidth(printf, i);
}
