/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag_fl_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:41:12 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 13:42:37 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_flag_float_no_add(t_print *printf, int i, int y)
{
	printf->width -= i + printf->precision;
	while (y++ < printf->width)
		ft_putchar_pf(' ', printf);
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		ft_putstr_pf(printf->itoa, printf);
	}
	else
		ft_putstr_pf(printf->itoa, printf);
}

void	print_flag_float_no(t_print *printf, int i, int y)
{
	int f;

	f = 0;
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	else if (printf->width > i + printf->precision)
		print_flag_float_no_add(printf, i, y);
	else if (printf->width <= i + printf->precision)
	{
		if (printf->itoa[0] == '-')
		{
			ft_putchar_pf('-', printf);
			printf->itoa++;
			ft_putstr_pf(printf->itoa, printf);
		}
		else
			ft_putstr_pf(printf->itoa, printf);
	}
}
