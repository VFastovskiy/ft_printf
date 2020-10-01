/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:40:50 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:14:52 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_perc(t_print *printf)
{
	int		i;
	int		y;
	int		f;

	i = 1;
	y = 0;
	f = ft_read_flag(printf->flags, printf);
	if (f == 7)
		print_char_minus(printf, i, y);
	else if (f == 5)
		print_char_zero(printf, i, y);
	else if (f == 12)
		print_char_mizer(printf, i, y);
	else
		print_char_noflag(printf, i, y);
}

void	print_perc(t_print *printf)
{
	printf->ch = '%';
	ft_print_perc(printf);
}
