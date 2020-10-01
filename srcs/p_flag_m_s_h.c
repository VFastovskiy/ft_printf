/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag_m_s_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:18:20 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 14:20:00 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_minspacehash_add2(t_print *printf)
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
		ft_putchar_pf(' ', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		printf->prec == 0 ? ft_putchar_pf('.', printf) : 1;
	}
}

void	print_minspacehash_add(t_print *printf, int i, int y)
{
	printf->width -= i + printf->precision;
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
		ft_putchar_pf(' ', printf);
		printf->width--;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	printf->prec == 0 ? ft_putchar_pf('.', printf) : 1;
	printf->prec == 0 ? printf->width-- : 1;
	while (y++ < printf->width)
		ft_putchar_pf(' ', printf);
}

void	print_flag_minspacehash(t_print *printf, int i, int y)
{
	int		f;

	f = 0;
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	else if (printf->width > i + printf->precision)
		print_minspacehash_add(printf, i, y);
	else if (printf->width <= i + printf->precision)
		print_minspacehash_add2(printf);
}
