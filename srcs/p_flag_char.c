/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:39:09 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 13:41:00 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char_minus(t_print *printf, int i, int y)
{
	if (printf->width > i)
	{
		printf->width -= i;
		ft_putchar_pf(printf->ch, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (printf->width <= i)
		ft_putchar_pf(printf->ch, printf);
}

void	print_char_noflag(t_print *printf, int i, int y)
{
	if (printf->width > i)
	{
		printf->width -= i;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		ft_putchar_pf(printf->ch, printf);
	}
	else if (printf->width <= i)
		ft_putchar_pf(printf->ch, printf);
}

void	print_char_zero(t_print *printf, int i, int y)
{
	if (printf->width > i)
	{
		printf->width -= i;
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		ft_putchar_pf(printf->ch, printf);
	}
	else if (printf->width <= i)
	{
		ft_putchar_pf(printf->ch, printf);
	}
}

void	print_char_mizer(t_print *printf, int i, int y)
{
	if (printf->width > i)
	{
		printf->width -= i;
		ft_putchar_pf(printf->ch, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (printf->width <= i)
		ft_putchar_pf(printf->ch, printf);
}
