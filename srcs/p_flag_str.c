/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:42:51 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:50:03 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_str_minus_add(t_print *printf, int i, int y, t_t *t)
{
	if (i > printf->prec && printf->prec >= printf->width && printf->prec > 0)
		while (t->x < t->a)
			ft_putchar_pf(printf->itoa[t->x++], printf);
	else if (i > printf->prec && printf->prec < printf->width \
										&& printf->prec > 0)
	{
		printf->width -= printf->prec;
		while (t->x < t->a)
			ft_putchar_pf(printf->itoa[t->x++], printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (i > printf->prec && i < printf->width && printf->prec <= -1)
	{
		printf->width -= i;
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (i > printf->prec && i >= printf->width && printf->prec <= -1)
		ft_putstr_pf(printf->itoa, printf);
}

void	print_str_minus(t_print *printf, int i, int y)
{
	t_t		t;

	t.a = printf->prec;
	t.x = 0;
	if (printf->prec == 0 && printf->width == 0)
		return ;
	else if (printf->prec == 0 && printf->width > 0)
	{
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		return ;
	}
	else if (printf->width == 0 && printf->prec <= -1)
		ft_putstr_pf(printf->itoa, printf);
	else if (i <= printf->prec && i < printf->width)
	{
		printf->width -= i;
		ft_putstr_pf(printf->itoa, printf);
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
	}
	else if (i <= printf->prec && i >= printf->width)
		ft_putstr_pf(printf->itoa, printf);
	else
		print_str_minus_add(printf, i, y, &t);
}

void	print_str_no_add(t_print *printf, int i, int y, t_t *t)
{
	if (i > printf->prec && printf->prec >= printf->width && printf->prec > 0)
		while (t->x < t->a)
			ft_putchar_pf(printf->itoa[t->x++], printf);
	else if (i > printf->prec && printf->prec < printf->width \
											&& printf->prec > 0)
	{
		printf->width -= printf->prec;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		while (t->x < t->a)
			ft_putchar_pf(printf->itoa[t->x++], printf);
	}
	else if (i > printf->prec && i < printf->width && printf->prec <= -1)
	{
		printf->width -= i;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	else if (i > printf->prec && i >= printf->width && printf->prec <= -1)
		ft_putstr_pf(printf->itoa, printf);
}

void	print_str_no(t_print *printf, int i, int y)
{
	t_t t;

	t.a = printf->prec;
	t.x = 0;
	if (printf->prec == 0 && printf->width == 0)
		return ;
	else if (printf->prec == 0 && printf->width > 0)
	{
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		return ;
	}
	else if (printf->width == 0 && printf->prec <= -1)
		ft_putstr_pf(printf->itoa, printf);
	else if (i <= printf->prec && i < printf->width)
	{
		printf->width -= i;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	else if (i <= printf->prec && i >= printf->width)
		ft_putstr_pf(printf->itoa, printf);
	else
		print_str_no_add(printf, i, y, &t);
}
