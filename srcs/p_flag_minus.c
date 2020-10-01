/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:20:25 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 14:21:41 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flag_minus_add3(t_print *printf)
{
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	else
	{
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_flag_minus_add2(t_print *printf, int y)
{
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else
	{
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
}

void	print_flag_minus_add(t_print *printf, int y)
{
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else
	{
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
}

void	print_flag_minus(t_print *printf, int i, int y)
{
	int		f;

	f = 0;
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	else if (printf->width > i + printf->precision)
	{
		printf->width -= i + printf->precision;
		if (printf->prec > 0)
			print_flag_minus_add(printf, y);
		else
			print_flag_minus_add2(printf, y);
	}
	else if (printf->width <= i + printf->precision)
		print_flag_minus_add3(printf);
}
