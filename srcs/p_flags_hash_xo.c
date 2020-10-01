/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_hash_xo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:14:47 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:16:36 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flag_hash_x_add(t_print *printf, int i, int y, char **x)
{
	printf->width -= i + printf->precision;
	while (y++ < printf->width)
		ft_putchar_pf(' ', printf);
	if (printf->itoa[0] != '0')
		ft_putstr_pf(*x, printf);
	while (printf->precision-- > 0)
		ft_putchar_pf('0', printf);
	ft_putstr_pf(printf->itoa, printf);
}

void	print_flag_hash_o_add(t_print *printf, int i, int y)
{
	printf->width -= i + printf->precision;
	while (y++ < printf->width)
		ft_putchar_pf(' ', printf);
	if (printf->itoa[0] != '0')
		ft_putchar_pf('0', printf);
	while (printf->precision-- > 0)
		ft_putchar_pf('0', printf);
	ft_putstr_pf(printf->itoa, printf);
}

void	print_flag_hash_x(t_print *printf, int i, int y, char c)
{
	int		f;
	char	*x;

	f = 0;
	x = (c == 'X' ? "0X" : "0x");
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	i = (printf->itoa[0] == '0' ? i : i + 2);
	if (printf->width > i + printf->precision)
		print_flag_hash_x_add(printf, i, y, &x);
	else if (printf->width <= i + printf->precision)
	{
		if (printf->itoa[0] != '0')
			ft_putstr_pf(x, printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_flag_hash_o(t_print *printf, int i, int y, char c)
{
	int		f;

	f = 0;
	if ((int_zero_prec_o(printf)) == 0 && (c != 'o' && c != 'O'))
		return ;
	i = (printf->itoa[0] == '0' ? i : i + 1);
	if (printf->precision > 0)
		printf->itoa[0] == '0' ? 1 : printf->precision--;
	if (printf->width > i + printf->precision)
		print_flag_hash_o_add(printf, i, y);
	else if (printf->width <= i + printf->precision)
	{
		if (printf->itoa[0] != '0')
		{
			ft_putchar_pf('0', printf);
		}
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}
