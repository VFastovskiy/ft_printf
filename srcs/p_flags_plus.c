/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:22:53 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:28:53 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flag_plus_add2(t_print *printf)
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
		ft_putchar_pf('+', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_flag_plus_add(t_print *printf, int i, int y)
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
	}
	else
	{
		ft_putchar_pf('+', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_flag_plus(t_print *printf, int i, int y)
{
	int		f;

	f = 1;
	printf->itoa[0] == '-' ? 1 : i++;
	if ((int_zero_prec(printf, y, f)) == 0)
	{
		printf->itoa[0] == '-' \
				? ft_putchar_pf('-', printf) : ft_putchar_pf('+', printf);
		return ;
	}
	else if (printf->width > i + printf->precision)
		print_flag_plus_add(printf, i, y);
	else if (printf->width <= i + printf->precision)
		print_flag_plus_add2(printf);
}
