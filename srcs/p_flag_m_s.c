/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag_m_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:15:23 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 14:18:06 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flag_minspace_add3(t_print *printf)
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
		ft_putchar_pf(' ', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_flag_minspace_add2(t_print *printf, int y)
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
		ft_putchar_pf(' ', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
}

void	print_flag_minspace_add(t_print *printf, int y)
{
	if (printf->itoa[0] == '-')
	{
		printf->itoa++;
		ft_putchar_pf('-', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else
	{
		ft_putchar_pf(' ', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
}

void	print_flag_minspace(t_print *printf, int i, int y)
{
	int		f;

	f = 0;
	printf->itoa[0] == '-' ? 1 : i++;
	if ((int_zero_prec(printf, y, f)) == 0)
	{
		printf->itoa[0] == '-' \
					? ft_putchar_pf('-', printf) : ft_putchar_pf(' ', printf);
		return ;
	}
	else if (printf->width > i + printf->precision)
	{
		printf->width -= i + printf->precision;
		if (printf->prec > 0)
			print_flag_minspace_add(printf, y);
		else
			print_flag_minspace_add2(printf, y);
	}
	else if (printf->width <= i + printf->precision)
		print_flag_minspace_add3(printf);
}
