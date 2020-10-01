/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_zerohash_xo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:34:41 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 18:58:54 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_flag_zerohash_o_add(t_print *printf, int i, int y)
{
	if (printf->width > i + printf->precision && printf->prec > 0)
	{
		printf->width -= i + printf->precision;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		if (printf->itoa[0] != '0')
			ft_putchar_pf('0', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		return (1);
	}
	else if (printf->width > i + printf->precision && printf->prec <= 0)
	{
		printf->width -= i;
		if (printf->itoa[0] != '0')
			ft_putchar_pf('0', printf);
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		return (1);
	}
	return (0);
}

int		print_flag_zerohash_x_add(t_print *printf, int i, int y, char **x)
{
	if (printf->width > i + printf->precision && printf->prec > 0)
	{
		printf->width -= i + printf->precision;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		if (printf->itoa[0] != '0')
			ft_putstr_pf(*x, printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		return (1);
	}
	else if (printf->width > i + printf->precision && printf->prec <= 0)
	{
		printf->width -= i;
		if (printf->itoa[0] != '0')
			ft_putstr_pf(*x, printf);
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		return (1);
	}
	return (0);
}

void	print_flag_zerohash_x(t_print *printf, int i, int y, char c)
{
	char	*x;

	printf->x = 0;
	x = (c == 'X' ? "0X" : "0x");
	if ((int_zero_prec(printf, y, printf->x)) == 0)
		return ;
	i = (printf->itoa[0] == '0' ? i : i + 2);
	printf->x = print_flag_zerohash_x_add(printf, i, y, &x);
	if (printf->x == 0)
	{
		if (printf->width <= i + printf->precision && printf->prec > 0)
		{
			if (printf->itoa[0] != '0')
				ft_putstr_pf(x, printf);
			while (printf->precision-- > 0)
				ft_putchar_pf('0', printf);
			ft_putstr_pf(printf->itoa, printf);
		}
		else if (printf->width <= i + printf->precision && printf->prec < 0)
		{
			if (printf->itoa[0] != '0')
				ft_putstr_pf(x, printf);
			ft_putstr_pf(printf->itoa, printf);
		}
	}
}

void	print_flag_zerohash_o(t_print *printf, int i, int y)
{
	int		f;

	i = (printf->itoa[0] == '0' ? i : i + 1);
	if (printf->precision > 0)
		printf->itoa[0] == '0' ? 1 : printf->precision--;
	f = print_flag_zerohash_o_add(printf, i, y);
	if (f == 0)
	{
		if (printf->width <= i + printf->precision && printf->prec > 0)
		{
			if (printf->itoa[0] != '0')
				ft_putchar_pf('0', printf);
			while (printf->precision-- > 0)
				ft_putchar_pf('0', printf);
			ft_putstr_pf(printf->itoa, printf);
		}
		else if (printf->width <= i + printf->precision && printf->prec < 0)
		{
			ft_putchar_pf('0', printf);
			ft_putstr_pf(printf->itoa, printf);
		}
	}
}
