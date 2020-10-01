/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_hexoctal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:16:45 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:18:04 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flags_minushash_x_add(t_print *printf, char **x)
{
	if (printf->itoa[0] != '0')
		ft_putstr_pf(*x, printf);
	while (printf->precision-- > 0)
		ft_putchar_pf('0', printf);
	ft_putstr_pf(printf->itoa, printf);
}

void	print_flags_minushash_x(t_print *printf, int i, int y, char c)
{
	int		f;
	char	*x;

	f = 0;
	x = (c == 'X' ? "0X" : "0x");
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	i = (printf->itoa[0] == '0' ? i : i + 2);
	if (printf->width > i + printf->precision)
	{
		printf->width -= i + printf->precision;
		if (printf->itoa[0] != '0')
			ft_putstr_pf(x, printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (printf->width <= i + printf->precision)
		print_flags_minushash_x_add(printf, &x);
}

void	print_flags_minushash_o_add(t_print *printf)
{
	if (printf->itoa[0] != '0')
		ft_putchar_pf('0', printf);
	while (printf->precision-- > 0)
		ft_putchar_pf('0', printf);
	ft_putstr_pf(printf->itoa, printf);
}

void	print_flags_minushash_o(t_print *printf, int i, int y, char c)
{
	int f;

	c = 1;
	f = 0;
	i = (printf->itoa[0] == '0' ? i : i + 1);
	if (printf->precision > 0)
		printf->itoa[0] == '0' ? 1 : printf->precision--;
	if (printf->width > i + printf->precision)
	{
		printf->width -= i + printf->precision;
		if (printf->itoa[0] != '0')
			ft_putchar_pf('0', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (printf->width <= i + printf->precision)
		print_flags_minushash_o_add(printf);
}
