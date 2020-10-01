/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_read_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:13:35 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 20:13:57 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_read_fl_add(t_print *printf, t_ibf *i)
{
	if (printf->width < 0 && i->f == 0)
		i->i += 7;
	if (printf->width < 0)
		printf->width *= -1;
}

int		ft_read_flag(char *flag, t_print *printf)
{
	t_ibf	i;

	i.i = 0;
	i.f = 0;
	while (*flag)
	{
		if (*flag == '#')
			i.i += 20;
		else if (*flag == ' ')
			i.i += 1;
		else if (*flag == '+')
			i.i += 40;
		else if (*flag == '0' && printf->width > 0)
			i.i += 5;
		else if (*flag == '-' || printf->width < 0)
		{
			i.i += 7;
			i.f++;
		}
		else
			break ;
		flag++;
	}
	ft_read_fl_add(printf, &i);
	return (i.i);
}

int		int_zero_prec(t_print *printf, int y, int f)
{
	if (printf->prec == 0 && printf->width == 0 && printf->fl == 0)
		return (0);
	else if (printf->prec == 0 && printf->width >= 0 && printf->fl == 1)
		return (1);
	else if (printf->prec == 0 && printf->width > 0)
	{
		if (f == 1)
			printf->width--;
		while (y++ < printf->width)
			ft_putchar_pf(' ', printf);
		return (0);
	}
	return (1);
}

int		int_zero_prec_o(t_print *printf)
{
	if (printf->prec == 0 && printf->width == 0 && printf->fl == 0)
		return (0);
	else if (printf->prec == 0 && printf->width >= 0 && printf->fl == 1)
		return (1);
	return (1);
}

int		analyze_length_add(char **str)
{
	int	i;

	i = 0;
	if ((*str)[0] == 'l' || (*str)[0] == 'z' || (*str)[0] == 'j')
	{
		(*str)++;
		i = 4;
	}
	else if ((*str)[0] == 'L')
	{
		(*str)++;
		i = 5;
	}
	return (i);
}
